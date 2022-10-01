#ifndef _VECTOR_H
#define _VECTOR_H

#include <cstdlib>
#include <iostream>
namespace vc{
    template <typename T>
    class Vector{
    private:
        T *data;
        int pos;
        int capacity;
        std::size_t siz;
        void swap(Vector<T> &rhs);
    public:
        explicit Vector(std::size_t size);

        Vector(const T *source, std::size_t size);

        Vector(const Vector<T> &rhs);

        Vector(Vector<T> &&rhs);

        Vector &operator=(const Vector<T> &rhs);
        Vector &operator=(Vector<T> &&rhs);
        T &operator[](std::size_t index) ;
        const T &operator[](std::size_t index) const;
        bool operator<(Vector<T> const &rhs);
        bool operator<=(Vector<T> const &rhs) const ;
        bool operator>(Vector<T> const &rhs)  const;
        bool operator>=(Vector<T> const &rhs) const;
        bool operator!=(const Vector<T> &rhs) const;
        bool operator==(const Vector<T> &rhs) const;
        /* // Not sure now, going to implement later
            Vector<T>& operator++();
            Vector<T>& operator--();
            Vector<T>  operator++(T);
            Vector<T>  operator--(T);

            Vector<T>& operator+=(const T &rhs);
            Vector<T>& operator-=(const T &rhs);

            Vector<T> operator+(const T &rhs)const;
            Vector<T> operator-(const T &rhs)const;
         */

        void Push_back(const T &value);
        std::size_t size() const;
        T *begin();
        T *end();
        const T *begin()const;
        const T *end() const;
        ~Vector();
    };

}




// Implementation
template <typename T>
vc::Vector<T>::Vector(std::size_t size) : data(new T[size]), siz(size){}

template <typename T>
vc::Vector<T>::Vector(const T *source, std::size_t size) : Vector(size) {
    std::copy(source, source + siz, data);
}

template <typename T>
vc::Vector<T>::Vector(const vc::Vector<T> &rhs): Vector(rhs.data, rhs.siz){}


template <typename T>
vc::Vector<T>::Vector(vc::Vector<T> &&rhs) : data(nullptr), siz(0) {
swap(rhs);
}

template <typename T>
vc::Vector <T> &vc::Vector<T>::Vector::operator=(const Vector<T> &rhs) {
    Vector<T> copy(rhs);
    swap(copy);
    return *this;
}


template <typename T>
vc::Vector <T> &vc::Vector<T>::Vector::operator=(Vector<T> &&rhs) {
    swap(rhs);
    return *this;
}
template <typename T>
T &vc::Vector<T>::Vector::operator[](std::size_t index) {
    return data[index];
}

template <typename T>
const T &vc::Vector<T>::operator[](std::size_t index) const{
    return data[index];
}




template <typename T>
bool vc::Vector<T>::operator<(const Vector<T> &rhs) {
    return data < rhs.data;
}

template <typename T>
bool vc::Vector<T>::operator<=(const Vector<T> &rhs) const {
    return data <= rhs.data;
}

template <typename T>
bool vc::Vector<T>::operator>(const Vector<T> &rhs) const {
    return data >  rhs.data;
}
template <typename T>
bool vc::Vector<T>::operator>=(const Vector<T> &rhs) const {
    return data >=  rhs.data;
}

template <typename T>
bool vc::Vector<T>::operator!=(const Vector<T> &rhs) const {
    return data != rhs.data;

}

template <typename T>
bool vc::Vector<T>::operator==(const Vector<T> &rhs) const {
    return data == rhs.data;
}





template <typename T>
std::size_t vc::Vector<T>::Vector::size() const {
    return siz;
}



template <typename T>
T *vc::Vector<T>::begin()  {
    return data;

}

template <typename T>
T *vc::Vector<T>::end() {
    return data + siz;
}

template <typename T>
const T *vc::Vector<T>::begin()const {
    return data;
}
template <typename T>
const T *vc::Vector<T>::end() const {
    return data + siz;
}



template <typename T>
vc::Vector<T>::~Vector() {
    if(data != nullptr){
        delete [] data;
    }
}
template <typename T>
void vc::Vector<T>::swap(Vector<T> &obj) {
    std::swap(obj.data, data);
    std::swap(obj.siz, siz);
}




#endif