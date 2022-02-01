#include <iostream>
#include <memory>
#include "Iterable.h"

using namespace Atakan;

namespace Atakan{
    template <typename T>
    class GTUVector : public Iterable<T>
    {
    public:
        GTUVector(int size);
        GTUVector() {}
        bool empty() override;
        int size() override;
        void erase(GTUIterator<T> iter) override;
        void clear() override;
        void add(T item) override;
        void insertSorted(int size_, T number);
        GTUIterator<T> begin() override;
        GTUIterator<T> end() override;
        GTUIteratorConst<T> cbegin() const;
        GTUIteratorConst<T> cend() const;
        T &operator[](int index);
        const T operator[](int index) const; 

    private:
        std::shared_ptr<T> sp;
        int capacity = 1; 
        int size_ = 0;
    };
}

