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
  
  while( input.compare("q") ){
    std::cin >> input;
    
    if( IsNumber(input) )
      calc.InsertFront( std::stod(input) );
    else if( input.compare("+") ){
      
    }
      



  }

}

int main(){
  std::cout<< " "<< IsNumber("12") <<IsNumber("1.5");
  calc();
}