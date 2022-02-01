#ifndef ITERABLE_H
#define ITERABLE_H
#include "GTUIterator.h"
#include "GTUIteratorConst.h"


namespace Atakan
{
    template <class T>
    class Iterable
    {
    public:
        virtual bool empty() = 0;
        virtual int size() = 0;
        virtual void erase(GTUIterator<T> iter) = 0;
        virtual void clear() = 0;
        virtual void add(T item) = 0;
        virtual GTUIterator<T> begin() = 0;
        virtual GTUIterator<T> end() = 0;
        virtual GTUIteratorConst<T> cbegin()const = 0;
        virtual GTUIteratorConst<T> cend()const = 0;
    };

} 

#endif