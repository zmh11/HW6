#include <iostream>
#include "dlist.h"
int main() {
  std::cout << "Hello World!\n";
  Dlist <int> list;
  //list.RemoveFront();
  list.InsertBack(5);
  list.InsertFront(6);
  //list.InsertBack(9);
  int k;
 // k = list.RemoveFront();
  std::cout << k<<" ";
   k = list.RemoveBack();
  std::cout<<k<<" ";
  //k = list.RemoveFront();
   std::cout<< list.IsEmpty();
}