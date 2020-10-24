#include <iostream>
#include "dlist.h"
#include <string>
#include <cstdlib>

bool IsNumber(const std::string& s){
    try
    {
        std::stod(s);
    }
    catch(...)
    {
        return false;
    }
    return true;
}

void calc (){
  Dlist<double> calc;
  std::string input = "";
  int size = 0;
  double o1; // operand 1
  double o2; // operand 2
  while( input.compare("q") ){
    std::cin >> input;
    
    if( IsNumber(input) ){
      calc.InsertFront( std::stod(input) );
      size++;
    } else if( (input == "+" )&& (size >= 2) ){ // add
      o1 = calc.RemoveFront();
      o2 = calc.RemoveFront();
      calc.InsertFront( (o1 + o2) );
      size --;
    } else if( (input == "-") && (size >= 2) ){ // subtract
      o1 = calc.RemoveFront();
      o2 = calc.RemoveFront();
      calc.InsertFront( (o1 - o2) );
      size --;
    }else if ( (input == "*") && (size>=2) ){
      o1 = calc.RemoveFront();
      o2 = calc.RemoveFront();
      calc.InsertFront( (o1 * o2) );
      size --;
    }
  
  std::cout<<std::endl;
  }



    while (!calc.IsEmpty())
  {
    o1 = calc.RemoveFront();
    std::cout<< o1 <<" ";
  }

}

int main(){
  //std::cout<< " "<< IsNumber("12") <<IsNumber("1.5");
  calc();
  
}