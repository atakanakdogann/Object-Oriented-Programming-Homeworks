#ifndef GTUITERATORCONST_H
#define GTUITERATORCONST_H

#include <string>
using namespace std;

namespace Atakan{
    template <class T>
    class GTUIteratorConst
    {
    public:
        GTUIteratorConst(T *ptr) : ptr_(ptr) {}
        GTUIteratorConst operator++();
        GTUIteratorConst operator--();
        inline const T &operator*() { return *ptr_; }
        inline const T *operator->() { return ptr_; }
        GTUIteratorConst& operator=(const GTUIteratorConst &other);
        inline bool operator==(const GTUIteratorConst &other) { return ptr_ == other.ptr_; }
        inline bool operator!=(const GTUIteratorConst &other) { return ptr_ != other.ptr_; }
        inline const T *getPtr_() const noexcept { return ptr_;}

    private:
        T *ptr_;
    };

}

#endif