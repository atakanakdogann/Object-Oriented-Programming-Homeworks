#ifndef GTUITERATOR_H
#define GTUITERATOR_H
#include <string>
using namespace std;

namespace Atakan{
    template <class T>
    class GTUIterator
    {
    public:
        GTUIterator(T *ptr) : ptr_(ptr) {}
        GTUIterator operator++();
        GTUIterator operator--();
        inline T &operator*() { return *ptr_; }
        inline T *operator->() { return ptr_; }
        GTUIterator& operator=(const GTUIterator &other);
        inline bool operator==(const GTUIterator &other) { return ptr_ == other.ptr_; }
        inline bool operator!=(const GTUIterator &other) { return ptr_ != other.ptr_; }
        inline T *getPtr_() const noexcept{ return ptr_;}

    protected:
        T *ptr_;
    };

}
#endif