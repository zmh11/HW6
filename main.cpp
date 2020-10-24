#include <iostream>
#include "dlist.h"
int main() {
  std::cout << "Hello World!\n";
  Dlist <int> list;

  std::cout<< list.IsEmpty();
  
  list.InsertFront(3);
  list.InsertBack(2);
  list.InsertBack(8);
  list.InsertBack(9);
  
  int k;
  
   k = list.RemoveBack();
  std::cout<<k<<" ";
     
     k = list.RemoveBack();
  std::cout<<k<<" ";

  k = list.RemoveFront();
  std::cout<<k<<" ";

  k = list.RemoveBack();
  std::cout<<k<<" ";

   k = list.RemoveBack();
  std::cout<<k<<" ";

 // k = list.RemoveBack();
  std::cout<<" "<< list.IsEmpty();

}