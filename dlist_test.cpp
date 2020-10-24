#include <iostream>
#include "dlist.h"
int main(){

  Dlist <int> list;
  int temp;
  // test list is empty 
  std::cout << "expetded output 1 : ";
  std::cout << list.IsEmpty() << std::endl << std::endl;

  // test add front remove front
  list.InsertFront(2);
  list.InsertFront(1);
  std::cout << "expected output 1 2 : ";
  temp = list.RemoveFront();
  std::cout << temp << " ";
  temp =list.RemoveFront();
  std::cout << temp << " " << std::endl << std::endl;

  //test add back and remove back 
  list.InsertBack(2);
  list.InsertBack(1);
  std::cout << "expected output 1 2 : ";
  temp = list.RemoveBack();
  std::cout << temp << " ";
  temp = list.RemoveBack();
  std::cout << temp << " " << std::endl << std::endl;

  // test empty with values 
  list.InsertBack(2);
  list.InsertBack(1);
  list.InsertFront(2);
  list.InsertFront(1);
  std::cout << "expected output 0 : ";
  std::cout << list.IsEmpty() << " ";
  

  


}