#include "src/GTUVector.h"

namespace Atakan{
    template <typename T>
    GTUVector<T>::GTUVector(int size_)
    {
        while (size_ > capacity)
        {
            capacity *= 2;
        }
        std::shared_ptr<T> spcopy(new T[capacity], std::default_delete<T[]>());
        sp = spcopy;
    }

    template <typename T>
    const T GTUVector<T>::operator[](int index) const
    {
        return sp.get()[index];
    }
    
    template <typename T>
    T &GTUVector<T>::operator[](int index) 
    {
        return sp.get()[index];
    }

    template <typename T>
    bool GTUVector<T>::empty()
    {
        return size_ == 0;
    }

    template <class T>
    int GTUVector<T>::size()
    {
        return size_;
    }

    template <class T>
    void GTUVector<T>::erase(GTUIterator<T> iter)
    {
        bool isAlreadyitem = false;
        for (auto iter_temp = this->begin(); iter_temp != this->end(); ++iter_temp)
        {
            if (*(iter_temp) == *iter)
            {
                for (auto iter2 = iter_temp; iter2 != this->end(); ++iter2)
                {
                    *(iter2) = *(iter2.getPtr_() + 1);
                    isAlreadyitem = true;
                }
            }
        }
        if (isAlreadyitem)
            this->size_--;
        if (this->size_ <= this->capacity / 2)
            this->capacity /= 2;
    }

    template <class T>
    void GTUVector<T>::clear()
    {
        this->sp = nullptr;
        *this = GTUVector(0);
    }

    template <typename T>
    void GTUVector<T>::insertSorted(int size_, T number)
    {
        int i;
        for (i = size_ - 1; (i >= 0 && (*this)[i] > number); i--)
            (*this)[i + 1] = (*this)[i];

        (*this)[i + 1] = number;
        this->size_++;
    }

    template <class T>
    void GTUVector<T>::add(T item)
    {
        if (size_ >= capacity)
        {
            capacity *= 2;
            std::shared_ptr<T> spcopy(new T[capacity], std::default_delete<T[]>());
            for (int i = 0; i < capacity / 2; i++)
            {
                spcopy.get()[i] = (*this)[i];
            }
            sp = nullptr;
            sp = spcopy;
        }
        insertSorted(size_, item);
        
    }

    template <class T>
    GTUIterator<T> GTUVector<T>::begin()
    {
        return GTUIterator<T>(sp.get());
    }
    template <class T>
    GTUIterator<T> GTUVector<T>::end()
    {
        return GTUIterator<T>(sp.get() + size_);
    }
    template <class T>
    GTUIteratorConst<T> GTUVector<T>::cbegin() const
    {
        return GTUIteratorConst<T>(sp.get());
    }
    
    template <class T>
    GTUIteratorConst<T> GTUVector<T>::cend() const
    {
        return GTUIteratorConst<T>(sp.get() + size_);
    }

}