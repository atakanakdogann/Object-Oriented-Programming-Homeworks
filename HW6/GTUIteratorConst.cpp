#include "src/GTUIteratorConst.h"
namespace Atakan{

	template<typename T>
	GTUIteratorConst<T> GTUIteratorConst<T>::operator++()
    {
        GTUIteratorConst i = *this;
        ptr_++;
        return i;
    }

    template<typename T>
    GTUIteratorConst<T> GTUIteratorConst<T>::operator--()
    {
        GTUIteratorConst i = *this;
        ptr_--;
        return i;
    }

    template<typename T>
    GTUIteratorConst<T>& GTUIteratorConst<T>::operator=(const GTUIteratorConst& other)
    {
        GTUIteratorConst i = *this;
        ptr_ = other.ptr_;
        return i;
    }
}