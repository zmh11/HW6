#include <iostream>
#include "dlist.h"
#include <string>
#include <cstdlib>




struct caller {
  int time_stamp;
  std::string name;
  std::string status;
  int duration;
};

void sim(){
  Dlist<caller*> calls;
  int number_of_calls;
  std::string tick = "Starting tick #";
  std::string call_from = "Call from ";
  std::string answer = "Answering call from ";
  std::cin >> number_of_calls;

  for( int k = 0; k< number_of_calls; k++){
    caller* c = new caller;
    std::cin >> c->time_stamp;
    std::cin >> c->name;
    std::cin >> c->status;
    std::cin >> c->duration;
    calls.InsertBack(c);
  }

  std::cout<<number_of_calls;
  Dlist<caller*> call_made; //if the time of call has been made
  Dlist<caller*> call_not_made; // if call has not been plased yet
  int tick_num = 0;
  while (!calls.IsEmpty()){
    std::cout << tick << tick_num << std::endl;
    while (!calls.IsEmpty()) { // plase calls in 2 lists of calls made or not made yet
      caller *c = calls.RemoveFront();
      if(c->time_stamp == tick_num){
        std::cout << call_from << c->name <<" a " <<c->status <<"member" <<std::endl<<std::endl;
        call_made.InsertBack(c);
      }else if (c->time_stamp < tick_num){
        call_made.InsertFront(c);
      }else{
        call_not_made.InsertBack(c);
      }
    }
    
    while(!call_made.IsEmpty()){    //select what call to answere
      
    }
  }
  /*
  while ( !calls.IsEmpty() ) {
    caller *r = calls.RemoveFront();
    std::cout << r->name << std::endl;
    delete r;
  }
*/



}

int main(){
sim();

}