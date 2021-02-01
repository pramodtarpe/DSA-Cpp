#include<iostream>
using namespace std;
struct DoublyLL{
  int data;
  struct DoublyLL* next;
  struct DoublyLL* prev;

  DoublyLL(){
    this->next = NULL;
    this->prev = NULL;
  }
};
