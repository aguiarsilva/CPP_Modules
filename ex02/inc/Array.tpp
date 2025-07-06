#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <stdexcept>

template <typename T>
Array<T>::Array() : arrSize(0), arrContents(NULL)
{}

template <typename T>
Array<T>::Array(size_t arrSize) : arrSize(arrSize), arrContents(new T[arrSize])
{}

template <typename T>
Array<T>::~Array()
{
    delete[] arrContents;
}

template <typename T>
Array<T>::Array(Array<T> const& other) : arrSize(other.arrSize), arrContents(new T[other.arrSize])
{
    for (size_t i = 0; i < arrSize; i++)
    {
        arrContents[i] = other.arrContents[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const& other)
{
    if (this != &other)
    {
        delete[] arrContents;
        this->arrSize = other.arrSize;
        this->arrContents = new T[other.arrSize];

        for (size_t i = 0; i < this->arrSize; i++)
        {
            arrContents[i] = other.arrContents[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index >= arrSize)
        throw std::out_of_range("Index out of bounds");
    return arrContents[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= arrSize)
        throw std::out_of_range("Index out of bounds");
    return arrContents[index];
}

template <typename T>
size_t Array<T>::size() const
{
    return arrSize;
}

#endif
