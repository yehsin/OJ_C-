#include<iostream>
#include<cstddef>
#include"12541.h"
using namespace std;
template<typename T>
vector<T>::vector(){
    SIZE = CAPACITY = 0;
    arr = NULL;
}

template<typename T>
void vector<T>::push_back(T x){
    if(CAPACITY == 0){
        CAPACITY =1;
        arr = new T[CAPACITY];
        arr[SIZE++] = x;
    }
    else if(SIZE == CAPACITY){
        CAPACITY = 2*CAPACITY;
        T *brr = new T[CAPACITY];
        for(size_t i = 0;i<SIZE;i++){
            brr[i] = arr[i];
        }
        delete []arr;
        arr = brr;
        brr = nullptr;
        arr[SIZE++] = x;
    }
    else arr[SIZE++] = x; 
    
    
}

template<typename T>
void vector<T>::pop_back(){
    if(SIZE == 0) return ;
    arr[--SIZE].~T();
}

template<typename T>
T& vector<T>::operator[](const int &x){
    return arr[x];
}

template<typename T>
const T& vector<T>::operator[](const int &x)const{
    return arr[x];
}

template<typename T>
size_t vector<T>::size(){
    return SIZE;
}

template<typename T>
size_t vector<T>::capacity(){
    return CAPACITY;
}

template<typename T>
void vector<T>::reserve(size_t x){
    if(x>CAPACITY){
        CAPACITY = x;
        T *brr = new T[CAPACITY];
        for(size_t i = 0;i<SIZE;i++){
            brr[i] = arr[i];
        }
        delete []arr;
        arr = brr;
        brr = nullptr;
    }
} 

template<typename T>
void vector<T>::clear(){
    for(size_t i = 0;i<=SIZE;i++){
        arr[i].~T();
    }
    SIZE = 0;
}



