#include <iostream>
#include "Vector.h"

// find algorithm STL my Implementation


template <typename IteratorType, typename T>
IteratorType find(IteratorType begin, IteratorType end, const T &value){
    while(begin != end  // pointer comparison
          && *begin != value){ // dereference value comparision
        ++begin; // next position
    }
    return begin;
}





int main() {

    vc::Vector<std::string> names(10);  // tests with strings
    std::cout <<"\n=============================================================\n" <<std::endl;

    names[0] = "Aman";
    names[1] = "Sara";
    names[2] = "Moa";
    names[3] = "Curly";
    names[4] = "Josh";
    names[5] = "Philip";
    names[6] = "Joe";
    names[7] = "Elen";
    names[8] = "Lilly";
    names[9] = "Robin";

    for(const auto &coll : names){
        std::cout << coll << ",  ";
    }
 std::cout <<"\n=============================================================\n" <<std::endl;

    std::string name;
    while(name != "-1"){
        std::cout << "Enter name you are looking for: (-1 = end: ";
        std::cin >> name;
        if(name != "-1"){
            auto position = ::find(names.begin(), names.end(), name);
            if(position != names.end()){
                std::cout << "Found at position " << (position - names.begin()) << '\n';
            } else{
                std::cout  << name << " not found!" << '\n';
            }

        }
    }



    // Testing with Integers



    std::cout <<"\n=============================================================\n" <<std::endl;
    vc::Vector<int> numbers(100);
    for(int i = 0; i <numbers.size(); ++i){
        numbers[i] = i*2;
    }

    int number = 0;
    while(number !=  -1){
        std::cout << "Enter number  you are looking for: (-1 = end: ";
        std::cin >> number;
        if(number != -1){
            auto position = ::find(numbers.begin(), numbers.end(), number);
            if(position != numbers.end()){
                std::cout << "Found at position " << (position - numbers.begin()) << '\n';
            } else{
                std::cout  << number << " not found!" << '\n';
            }

        }
    }


    std::cout <<"\n=============================================================\n" <<std::endl;
    int a = 2;
    int b = 3;

      vc::Vector<int> temp(numbers.begin(), 101);
     if(numbers[a] == temp[b] ){
         std::cout << "The value are the same: " << std::endl;
         std::cout << numbers[a] << " numbers" << std::endl;
         std::cout << temp[b] << " temp" << std::endl;
     }else{
         std::cout << "Not sam at position: "<< std::endl;
         std::cout << numbers[a] << " numbers" << std::endl;
         std::cout << temp[b] << " temp" << std::endl;
     }
    std::cout <<"\n=======================Comparing======================================\n" <<std::endl;
    if(numbers[a] < temp[b] ){
        std::cout << "The value in numbers is less than value in temp: " << std::endl;
        std::cout << numbers[a] << " numbers" << std::endl;
        std::cout << temp[b] << " temp" << std::endl;
    }else{
        std::cout << "The value in temp is less than value in numbers: " << std::endl;
        std::cout << numbers[a] << " numbers" << std::endl;
        std::cout << temp[b] << " temp" << std::endl;
    }




    std::cout <<"\n\n=========================Comparing====================================\n" <<std::endl;

    for(size_t pos = 0; pos < temp.size(); ++pos){
        if(numbers[pos] == temp[pos]){
            std::cout << "The same value! Temp == " << temp[pos] << std::endl;
            std::cout << "The same value! Numbers == " << numbers[pos] << std::endl;
            std::cout << std::endl;
        } else{
            std::cout << "The not same value! Temp == " << temp[pos] << std::endl;
            std::cout << "The not same value! Numbers == " << numbers[pos] << std::endl;
        }
    }





    return 0;
}
