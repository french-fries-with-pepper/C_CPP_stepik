#include <cstddef>
#include <iostream>
using namespace std;

template <class T>
struct Array
{
    // Список операций:
    //
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
    //
    explicit Array(size_t size = 0, const T &value = T())
        : data_(new T[size]), size_(size)
    {
        for (size_t i = 0; i < size; i++)
        {
            data_[i] = value;
        }
    }

    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.

    Array(const Array &a)
        : data_(new T[a.size()]), size_(a.size())
    {
        for (size_t i = 0; i < size_; ++i)
        {
            data_[i] = a[i];
        }
    }
    //   деструктор, если он вам необходим.
    //
    ~Array()
    {
        delete[] data_;
    }

    //
    Array &operator=(const Array &a)
    {
        if (this != &a)
        {
            delete[] data_;
            size_ = a.size();
            data_ = new T[size_];
            for (size_t i = 0; i < size_; ++i)
            {
                data_[i] = a[i];
            }
        }
        return *this;
    }
    //   оператор присваивания.
    //
    size_t size() const
    {
        return size_;
    }
    //   возвращает размер массива (количество
    //                              элементов).
    //
    T &operator[](size_t i)
    {
        return data_[i];
    }
    const T &operator[](size_t i) const
    {
        return data_[i];
    }
    //   две версии оператора доступа по индексу.
private:
    T *data_;
    size_t size_;
};

int main()
{

    Array<int> ai(5, 1);
    Array<int> bi;

    ai[3] = 5;

    bi = ai;

    for (size_t i = 0; i < bi.size(); i++)
    {
        cout << bi[i] << endl;
    }

    return 0;
}