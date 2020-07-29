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
    MemCellData *next;
};

/* приводим буфер  к нужному виду. */
void mysetup(void *buf, size_t size)
{
    int infoSize = sizeof(MemCellData);
    MemCellData * stuffPtr = (MemCellData *)buf;
    MemCellData * stuffPtrTail = (MemCellData *)((char *)buf + infoSize);
    *stuffPtr={
        0,
        (void*)stuffPtrTail,
        false,
        stuffPtrTail+1
    };
    *stuffPtrTail=*stuffPtr;



    char *startCell = (char *)buf + 3*infoSize;      // -> start effective area
    char *endCell = (char *)buf + size - infoSize; // -> end ^
    size_t effectiveSize = size - 4 * infoSize;
    MemCellData *headPtr = (MemCellData *)((char*)buf+2*infoSize);
    *headPtr = {
        effectiveSize,
        (void *)startCell,
        true,
        NULL};
    MemCellData *tailPtr = (MemCellData *)endCell;
    *tailPtr = *headPtr;
}

/* print all ifo about whole buffer */
void printBufferInfo(void *buff)
{

    MemCellData *cur = (MemCellData *)buff;
    long counter = 0;

    for (;;)
    {
        if (cur == NULL)
        {
            break;
        }
        std::cout << "cell " << counter << "\n";
        std::cout << "    cell size is " << cur->cellSize << " bytes\n";
        std::string state = cur->isFree ? "free" : "used";
        std::cout << "    this cell is " << state << "\n";
        if (cur->next != NULL)
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
    void *res = NULL;
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
        if (cur == NULL)
        {
            std::cout << "can't allocate\n";
            return NULL;
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

    if ( head->isFree&&head->next!=NULL&&head->next->isFree)
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
    MemCellData * prevHeadPtr = (MemCellData *)((char *)((headPtr-1)->cellBody) - sizeof(MemCellData));
    mergeFreedDouble(prevHeadPtr);
}

int main()
{

    size_t SIZE = 1024*870;
    size_t CHUNK = 16;

    int infoSize = sizeof(MemCellData);

    myBuff = createBuffer(SIZE);
    //std::cout<<(long long)myBuff<<"\n";
    std::cout << "----------------Buffer created-----------------\n";
    std::cout << "----------size of head/tail is " << infoSize << "--------------\n";

    mysetup(myBuff, SIZE);
    //std::cout<<(long long)myBuff<<"\n";

    printBufferInfo(myBuff);
    std::cout << "---------------Start allocation----------------\n";
    auto c1 = myalloc(10000);
    auto c2 = myalloc(20000);
    auto c3 = myalloc(30000);
    auto c4 = myalloc(40000);
    auto c5 = myalloc(50000);
    auto c6 = myalloc(60000);

    printBufferInfo(myBuff);

    myfree(c1);
    myfree(c2);

    myfree(c6);
    //myfree(c5);

    printBufferInfo(myBuff);  
 

    return 0;
}