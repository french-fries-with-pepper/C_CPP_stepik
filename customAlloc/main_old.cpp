#include <iostream>
#include <malloc.h>
void *myBuff;

/* служебная функция, создает буфер нужного размера */
void *createBuffer(size_t size)
{
    return malloc(size);
}

struct MemCellData
{
    size_t cellSize;
    void *cellBody;
    bool isFree;
    MemCellData *prev;
    MemCellData *next;
};

/* приводим буфер  к нужному виду. */
void mysetup(void *buf, size_t size)
{
    int infoSize = sizeof(MemCellData);

    char *startCell = (char *)buf + infoSize;      // -> start effective area
    char *endCell = (char *)buf + size - infoSize; // -> end ^
    size_t effectiveSize = size - 2 * infoSize;
    //std::cout << "size is: " << size << " start at: " << (long)startCell << " end at: " << (long)endCell;
    //std::cout << "\neffective size is: " << (long)endCell - (long)startCell << " " << effectiveSize << "\n";

    // create head, tail and put in at buf and endCell.
    MemCellData head = {
        effectiveSize,
        (void *)startCell,
        true,
        nullptr,
        nullptr};
    MemCellData tail = head;

    MemCellData *headPtr = (MemCellData *)buf;
    MemCellData *tailPtr = (MemCellData *)endCell;

    *headPtr = head;
    *tailPtr = tail;
}

/* print all ifo about whole buffer */
void printBufferInfo(void *buff)
{

    MemCellData *cur = (MemCellData *)buff;
    long counter = 0;

    for (;;)
    {
        if (cur == nullptr)
        {
            break;
        }
        std::cout << "cell " << counter << "\n";
        //if(cur->prev!=nullptr) std::cout << "    cell prev size is " << cur->prev->cellSize << " bytes\n";
        std::cout << "    cell size is " << cur->cellSize << " bytes\n";
        std::string state = cur->isFree ? "free" : "used";
        std::cout << "    this cell is " << state << "\n";
        if (cur->next != nullptr)
            std::cout << "    cell next size is " << cur->next->cellSize << " bytes\n";

        cur = cur->next;
        ++counter;
    }
    std::cout << "Total " << counter << " cells\n";
    std::cout << "End printing..................................\n";

    return;
};

/*will shrink free cell, that have enougth space to alloc
size bytes(and all MemCellData). Also size must be small
(no checks here). And return pointer to allocated memory*/
void *shrinkCell(MemCellData *cell, size_t size)
{
    void *res = nullptr;
    MemCellData *savedNext = cell->next;
    size_t newSize = cell->cellSize - size - 2 * sizeof(MemCellData);

    cell->cellSize = newSize;
    MemCellData *cellTail = (MemCellData *)((char *)cell->cellBody + newSize);
    *cellTail = *cell;

    MemCellData *newCell = cellTail + 1;
    *newCell = {
        size,
        (void *)(newCell + 1),
        false,
        cell,
        savedNext};
    cell->next = newCell;
    cellTail->next = newCell;

    MemCellData *newCellTail = (MemCellData *)((char *)newCell->cellBody + size);
    *newCellTail = *newCell;
    return newCell->cellBody;
};

void *myalloc(size_t size)
{
    MemCellData *cur = (MemCellData *)myBuff;
    for (;;)
    {
        if (cur == nullptr)
        {
            std::cout << "can't allocate\n";
            return nullptr;
        };
        if (cur->isFree && cur->cellSize > size + 2 * sizeof(MemCellData))
        {
            return shrinkCell(cur, size);
        };
        if (cur->isFree && cur->cellSize >= size)
        {
            cur->isFree = false;
            MemCellData *curTail = (MemCellData *)((char *)cur->cellBody + cur->cellSize);
            curTail = cur;
            return cur->cellBody;
        }
        cur = cur->next;
    };
}

void mergeFreedDouble(MemCellData *hPtr)
{
    MemCellData *head = hPtr;
    MemCellData *tail = (MemCellData *)((char *)hPtr->cellBody + hPtr->cellSize);

    /* if (head->prev->isFree)
    {

        head = head->prev;
        head->isFree = true;
        head->next = tail->next;
        head->cellSize = size_t((char*)tail - (char*)head->cellBody);
        *tail = *head;
    } */

    if (tail->next->isFree)
    {
        tail = (MemCellData *)((char *)tail->next->cellBody + tail->next->cellSize);
        head->next = tail->next;
        head->cellSize = size_t((char *)tail - (char *)head->cellBody);
        head->isFree = true;
        *tail = *head;
    }
    return;
};

void myfree(void *p)
{
    MemCellData *headPtr = (MemCellData *)((char *)p - sizeof(MemCellData));
    MemCellData *tailPtr = (MemCellData *)((char *)p + headPtr->cellSize);
    headPtr->isFree = true;
    tailPtr->isFree = true;
    mergeFreedDouble(headPtr);
}

int main()
{

    struct T
    {
        long long a;
        long long b;
        long long c;
    };

    size_t SIZE = 100 * 1024;
    size_t CHUNK = 16;

    int infoSize = sizeof(MemCellData);

    myBuff = createBuffer(SIZE);
    std::cout << "----------------Buffer created-----------------\n";
    std::cout << "----------size of head/tail is " << infoSize << "--------------\n";

    mysetup(myBuff, SIZE);
    printBufferInfo(myBuff);
    std::cout << "---------------Start allocation----------------\n";
    auto c1 = myalloc(100);
    auto c2 = myalloc(200);
    auto c3 = myalloc(300);
    auto c4 = myalloc(400);
    auto c5 = myalloc(500);
    auto c6 = myalloc(600);

    printBufferInfo(myBuff);
    myfree(c2);
    myfree(c3);
    printBufferInfo(myBuff); 

    /* size_t total = 0;
    for(;;){
        auto cur = myalloc(CHUNK*=2);
        if(cur==nullptr) break;
        total+=CHUNK;
    };
    

    printBufferInfo(myBuff);
    std::cout<< total<< " Bytes was allocated ("<< total/(SIZE/100)<<")%\n"; */

    return 0;
}