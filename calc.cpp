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
      calc.InsertFront( (o2 - o1) );
      size --;
    }else if ( (input == "*") && (size>=2) ){ // mutipiply
      o1 = calc.RemoveFront();
      o2 = calc.RemoveFront();
      calc.InsertFront( (o1 * o2) );
      size --;
    }else if ( (input == "/") && (size>=2) ){ // divide
      o1 = calc.RemoveFront();
      o2 = calc.RemoveFront();
      if(o1 != 0){
        calc.InsertFront( (o2 / o1) );
        size --;
      }
      else{
        std::cout << "Divide by zero\n";
        calc.InsertFront(o2);
        calc.InsertFront(o1);
      }
    }else if ( (input == "n") && (size>=1) ){ // negate
      o1 = calc.RemoveFront();
      calc.InsertFront( (o1 * (-1)) );
    }else if ( (input == "d") && (size>=1) ){ // duplicate
      o1 = calc.RemoveFront();
      calc.InsertFront( o1 );
      calc.InsertFront( o1 );
      size++;
    }else if ( (input == "r") && (size>=2) ){ // reverse
      o1 = calc.RemoveFront();
      o2 = calc.RemoveFront();
      calc.InsertFront(o2);
      calc.InsertFront(o1);
    }else if ( (input == "p") && (size>=1) ){ // print
      o1 = calc.RemoveFront();
      std::cout << o1;
      calc.InsertFront(o1);
      std::cout<<std::endl;
    }else if( input == "c"){ // clear
      while (!calc.IsEmpty()) 
        o1 = calc.RemoveFront();
    }else if( input == "a" ){
      double temp[size-1];
      for(int k = 0; k <size; k++){
        o1 = calc.RemoveFront();
        temp[k] = o1;
        std::cout << o1 << " ";
      }

      std::cout << std::endl;
      for(int k = 0; k <size; k++){ // place values back 
        calc.InsertBack(temp[k]);
      }
    }else if (size < 2 && input != "q"){
      std::cout << "Not enough operands\n";
    }else if(input != "q") {
      std::cout << "Bad input\n"; 
    }
    
  }

}
