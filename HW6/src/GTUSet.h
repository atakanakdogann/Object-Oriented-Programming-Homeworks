#include <iostream>
#include <memory>
#include "Iterable.h"

using namespace Atakan;

namespace Atakan{
    template <typename T>
    class GTUSet : public Iterable<T>
    {
    public:
        GTUSet(int size);
        GTUSet() {}
        bool empty() override;
        int size() override;
        void erase(GTUIterator<T> iter) override;
        void clear() override;
        void add(T item) override;
        GTUIterator<T> begin() override;
        GTUIterator<T> end() override;
        GTUIteratorConst<T> cbegin() const override;
        GTUIteratorConst<T> cend() const override;
        T &operator[](int index);
        const T operator[](int index) const;
        bool contains(T value);
        void insertSorted(int size, T numberInserted);
        

    private:
        std::shared_ptr<T> sp;
        int capacity = 1;
        int size_ = 0;
    };

}

