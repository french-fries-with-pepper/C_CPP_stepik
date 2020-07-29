#include <cstddef>

template <typename T>
struct Array
{
    // Список операций:
    //
    // explicit Array(size_t size, const T& value = T())
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Если у класса нет конструктора
    //   по умолчанию, то второй аргумент этого конструктора
    //   обязателен.
    explicit Array(size_t size = 0, const T &value = T())
    {
        size_ = size;
        data_ = (T *)new char[size_ * sizeof(T)];
    }
    // Array()
    //   конструктор класса, который можно вызвать
    //   без параметров. Должен создавать пустой
    //   Array.
    Array()
        : data_(new T[0]), size_(0)
    {
    }
    // Array(const Array &)
    //   конструктор копирования, который создает
    //   копию параметра. Для типа T оператор
    //   присваивания не определен.
    Array(const Array &a)
        : data_(new T[a.size()]), size_(a.size())
    {
        for (size_t i = 0; i < size_; ++i)
        {
            data_[i] = a[i];
        }
    }
    // ~Array()
    //   деструктор, если он вам необходим.
    ~Array()
    {
        for (size_t i = 0; i < size; i++)
        {
            delete data_[i];
        }

        delete[](char *) data_;
    }
    // Array& operator=(...)
    //   оператор присваивания.
    Array &operator=(const Array &a)
    {
        if (this != &a)
        {
            for (size_t i = 0; i < size; i++)
            {
                delete data_[i];
            }

            delete[](char *) data_;
            size_ = a.size();
            data_ = new T[size_];
            for (size_t i = 0; i < size_; ++i)
            {
                data_[i] = a[i];
            }
        }
        return *this;
    }

    size_t size() const
    {
        return size_;
    }

    T &operator[](size_t i)
    {
        return data_[i];
    }

    const T &operator[](size_t i) const
    {
        return data_[i];
    }

private:
    T *data_;
    size_t size_;
};