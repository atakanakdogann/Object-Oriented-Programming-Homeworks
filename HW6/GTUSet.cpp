#include "src/GTUSet.h"

namespace Atakan{
    template <typename T>
    GTUSet<T>::GTUSet(int size_)
    {
        while (size_ > capacity)
        {
            capacity *= 2;
        }
        std::shared_ptr<T> spcopy(new T[capacity], std::default_delete<T[]>());
        sp = spcopy;
    }

    template <typename T>
    const T GTUSet<T>::operator[](int index) const
    {
        return sp.get()[index];
    }

    template <typename T>
    T &GTUSet<T>::operator[](int index)
    {
        return sp.get()[index];
    }

    template <typename T>
    bool GTUSet<T>::contains(T value)
    {
        for (int i = 0; i < size_; i++)
        {
            if ((*this)[i] == value)
            {
                return true;
            }
        }
        return false;
    }

    template <typename T>
    void GTUSet<T>::insertSorted(int size_, T number)
    {
        int i;
        for (i = size_ - 1; (i >= 0 && (*this)[i] > number); i--)
            (*this)[i + 1] = (*this)[i];

        (*this)[i + 1] = number;
        this->size_++;
    }

    template <typename T>
    bool GTUSet<T>::empty()
    {
        if (size_ == 0)
        {
            return true;
        }
        else
            return false;
    }

    template <class T>
    int GTUSet<T>::size()
    {
        return size_;
    }

    template <class T>
    void GTUSet<T>::erase(GTUIterator<T> iter)
    {
        bool isAlreadyInserted = false;
        for (auto iter_temp = this->begin(); iter_temp != this->end(); ++iter_temp)
        {
            if (*(iter_temp) == *iter)
            {
                for (auto iter2 = iter_temp; iter2 != this->end(); ++iter2)
                {
                    *(iter2) = *(iter2.getPtr_() + 1);
                    isAlreadyInserted = true;
                }
            }
        }
        if (isAlreadyInserted)
            this->size_--;
        if (this->size_ <= this->capacity / 2)
            this->capacity /= 2;
    }

    template <class T>
    void GTUSet<T>::clear()
    {
        this->sp = nullptr;
        *this = GTUSet(0);
    }

    template<class T>
    void GTUSet<T>::add(T item)
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
    GTUIterator<T> GTUSet<T>::begin()
    {
        return GTUIterator<T>(sp.get());
    }

    template <class T>
    GTUIterator<T> GTUSet<T>::end()
    {
        return GTUIterator<T>(sp.get() + size_);
    }

    template <class T>
    GTUIteratorConst<T> GTUSet<T>::cbegin() const
    {
        return GTUIteratorConst<T>(sp.get());
    }
    
    template <class T>
    GTUIteratorConst<T> GTUSet<T>::cend() const
    {
        return GTUIteratorConst<T>(sp.get() + size_);
    }
}