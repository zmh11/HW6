#include <iostream>
#include <string>
#include "dlist.h"

using namespace std;

enum Job {STUDENT, FACULTY, STAFF};

struct Record {
  string name;
  string uniqname;
  Job job;
};

int main() {

  Dlist<Record*> catsweb; //records are big, so store pointer

  Record* p = new Record;
  p->name = "Andrew DeOrio";
  p->uniqname = "awdeorio";
  p->job = FACULTY;
  catsweb.InsertFront( p );

  Record* f = new Record;
  f->name = "Andrew DeOrio";
  f->uniqname = "testing";
  f->job = FACULTY;
  catsweb.InsertFront( f );

  Record* q = new Record;
  q->name = "Andrew DeOrio";
  q->uniqname = "cool name";
  q->job = FACULTY;
  catsweb.InsertBack( q );

  Dlist<Record*> test;

  cout <<test.IsEmpty() <<" cats" <<catsweb.IsEmpty() << endl;
  // do something with "catsweb"
  test = catsweb;
cout<<endl;
while ( !test.IsEmpty() ) {
    Record *a =test.RemoveBack();
    cout << a->uniqname <<" "<<a<< endl;
    //delete a;
  }
 

cout <<test.IsEmpty() <<" cats" <<catsweb.IsEmpty()<<endl;  // copy is fucking up fix it !!!!! its not a deep copy!!!!!
  Record* w = new Record;
  w->name = "Andrew DeOrio";
  w->uniqname = "lol";
  w->job = FACULTY;
  catsweb.InsertBack( w );


    while ( !catsweb.IsEmpty() ) {
      
    Record *r = catsweb.RemoveBack();
    cout << r->uniqname <<" "<<r << endl;
  delete r;
 }


  return 0;
}
