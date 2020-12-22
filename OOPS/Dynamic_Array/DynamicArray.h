#include<iostream>
using namespace std;

template<class T>
class DynamicArray{
public:
  int index;
  int capacity;
  int size ;
  T *array ;
public:
  DynamicArray(){
    this->index = 0;
    this->size = 0;
    this->capacity = 8;
    array = new T[capacity];
  }
//methods for dynamic array
  void insert(T data){
    if(size<capacity){
      array[index] = data;
      index++;
      size++;
    }
    else if(size == capacity){
      T *temp = this->array;
      capacity *= 2;
      array = new T[capacity];
      for(int i=0;i<size;i++){
        this->array[i] = temp[i];
      }
      delete[] temp;
      this->array[index] = data;
      size++;
      index++;
    }
  }
  T remove(){
    T valueToBeReturned = this->array[--index];
    this->array[index] = 0;
    size--;
    return valueToBeReturned;
  }
  int getSize(){
    return size;
  }
  int getCapacity(){
    return capacity;
  }
  void display(){
    for(int i=0;i<size;i++){
      cout<< array[i] <<" ";
    }
    cout<<endl;
  }

};
