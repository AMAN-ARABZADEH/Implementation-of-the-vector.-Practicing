//
// Created by amana on 2022-10-01.
//

#ifndef STL_UTILITY_HELPER_H
#define STL_UTILITY_HELPER_H
// find algorithm STL my Implementation
#include <cstdlib>

template <typename IteratorType, typename T>
IteratorType find(IteratorType begin, IteratorType end, const T &value){
    while(begin != end  // pointer comparison
          && *begin != value){ // dereference value comparision
        ++begin; // next position
    }
    return begin;
}



// Bubble sort Implementation
template <typename  T, typename CompareType>
void bubble_sort(T *array, std::size_t size, const CompareType &Compare){
    for(auto i = 0; i < size; ++i){
        for(auto j = i+1; j < size; ++j){
            if(Compare(array[i], array[j])){
                // Exchange
                const T temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// Displays the collection
template <typename  T>
void Display( T *array, size_t size) {
    std::cout << "===================================================" << std::endl;
    for(auto i = 0; i < size; ++i){
        std::cout <<  array[i] << " ";
    }
    std::cout << "\n===================================================" << std::endl;
}




// comparison operation
template <typename  T>
struct less{
        bool operator()( const T &x,const  T &y)const{
            return (x < y);
        }
    };

// comparison operation
template <typename  T>
struct greater{
    bool operator()( const T &x,const  T &y)const{
        return (x > y);
    }
};
#endif //STL_UTILITY_HELPER_H
