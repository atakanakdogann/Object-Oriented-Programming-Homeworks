#include "src/GTUIterator.h"
namespace Atakan{

    template<typename T>
    GTUIterator<T> GTUIterator<T>::operator++()
    {
        GTUIterator i = *this;
        ptr_++;
        return i;
    }

    template<typename T>
    GTUIterator<T> GTUIterator<T>::operator--()
    {
        GTUIterator i = *this;
        ptr_--;
        return i;
    }

    template<typename T>
    GTUIterator<T>& GTUIterator<T>::operator=(const GTUIterator& other)
    {
        GTUIterator i = *this;
        ptr_ = other.ptr_;
        return i;
    }
}