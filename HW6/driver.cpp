#include <iostream>
#include "GTUVector.cpp"
#include "GTUSet.cpp"
#include "GTUIterator.cpp"
#include "GTUIteratorConst.cpp"

using namespace std;
using namespace Atakan;

template<typename T>
void print (T i) {  
  cout << i << ' ' ;
}

template <typename T>
void printSet(GTUSet<T> set)
{
    cout << "Size of set is " << set.size() << endl;
    cout << "Empty of set is " << set.empty() << endl;
    for (GTUIterator<T> i = set.begin(); i != set.end(); ++i)
    {
        std::cout << *i << " ";
    }
    cout << endl;
}

template <typename T>
void printVector(GTUVector<T> vector)
{
    cout << "Size of vector is " << vector.size() << endl;
    cout << "Empty of vector is " << vector.empty() << endl;
    for (GTUIterator<T> i = vector.begin(); i != vector.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}

template <typename T>
GTUIterator<T> find(GTUIterator<T> first, GTUIterator<T> last, T input){
    for (GTUIterator<double> i = first; i != last; ++i)
    {
        if(*i == input){
            return i;
        }
    }
    return last;
}

template <typename T>
GTUIterator<T> sort(GTUIterator<T> first, GTUIterator<T> last)
{
    GTUIterator<T> temp;    
    for (GTUIterator<T> i = first; i != last; ++i)
    {
        if (i > i+1)
        {
            temp = i;
            i = i+1;
            i+1 = temp;
        }
        
    }
    return first;
}

template <typename T>
GTUIterator<T> for_each(GTUIterator<T> first, GTUIterator<T> last, void (*f)(T)){
    
    for (GTUIterator<T> i = first; i != last; ++i)
    {
        (*f)(*i);
    }
    return last;

}
int main()
{
     cout << "--------SET--------"<< endl;
    GTUSet<double> set1(5);
    GTUIterator<double> iter = set1.begin();
    set1.erase(iter);
    set1.add(2.5);
    set1.add(4.5);
    set1.add(5.3);
    set1.add(8.1);
    for_each(set1.begin(),set1.end(),print);  
    cout << endl;  
    find(set1.begin(),set1.end(),10.0) == set1.end() ? cout << "10.0 Not in the set\n" : cout << "10.0 In the set\n" ;

    GTUIterator<double> i = set1.begin();
    ++i;
    set1.erase(i);
    printSet(set1);
    cout << "--------VECTOR--------"<< endl;

    GTUVector<int> vector1(3);
    vector1.add(6);
    vector1.add(45);
    printVector(vector1);


    return 0;
}