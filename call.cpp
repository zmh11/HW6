#include <iostream>
#include "dlist.h"
#include <string>
#include <cstdlib>




struct caller {
  int time_stamp;
  std::string name;
  std::string status;
  int duration;
  int caller_compare;
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
    if(c->status =="platinum")
      c->caller_compare = 4;
    else if (c->status =="gold")
      c->caller_compare = 3;   
    else if (c->status =="silver") 
      c->caller_compare = 2;   
    else if (c->status =="none"){ 
      c->caller_compare = 1;   
      c->status = "regular";
      }

    calls.InsertBack(c);
  }

  //std::cout<<number_of_calls;
  Dlist<caller*> call_made; //if the time of call has been made
  Dlist<caller*> call_not_made; // if call has not been plased yet
  int tick_num = 0;
  caller* user;
  caller* priority;
  caller* temp;
  bool can_take_call=true;
  int time_of_call;


 while (!calls.IsEmpty()){
    std::cout << tick << tick_num << std::endl;

    while (!calls.IsEmpty()) { // plase calls in 2 lists of calls made or not made yet
      caller *c = calls.RemoveFront();
      if(c->time_stamp == tick_num){
        std::cout << call_from << c->name <<" a " <<c->status <<" member" <<std::endl;
        call_made.InsertBack(c);
      }else if (c->time_stamp < tick_num){
        call_made.InsertFront(c);
      }else{
        call_not_made.InsertBack(c);
      }
    }

 
    priority = call_made.RemoveFront();// select caller 
    while(!call_made.IsEmpty()){
      user = call_made.RemoveFront();
      if(priority->caller_compare < user->caller_compare){
        temp = priority;
        priority = user;
        user = temp;
      }
      calls.InsertFront(user);
    }

    if(can_take_call){
    std::cout<<answer << priority->name<< std::endl;
    time_of_call = priority->duration; 
    }
    else
      calls.InsertFront(priority);

    while (!call_not_made.IsEmpty())
    {
      caller *c=call_not_made.RemoveFront();
      calls.InsertBack(c);
    }
    
     //std::cout<<time_of_call<< " time left on call" <<std::endl;
    tick_num++;
    time_of_call--;
    if(time_of_call!=0){
      can_take_call=false;
      }
    else
    {
      can_take_call = true;
    }
    
  }
std::cout << tick << tick_num << std::endl;  


}

int main(){
sim();

}