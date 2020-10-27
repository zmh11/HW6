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
  test = catsweb;
  cout <<test.IsEmpty() <<" " <<catsweb.IsEmpty();
  // do something with "catsweb"
  
while ( !test.IsEmpty() ) {
    Record *a =test.RemoveBack();
    cout << a->uniqname << endl;
    delete a;
  }
cout <<test.IsEmpty() <<" " <<catsweb.IsEmpty();
  // don't forget to delete objects on the heap
    while ( !catsweb.IsEmpty() ) {
    Record *r = catsweb.RemoveFront();
    cout << r->uniqname << endl;
    //delete r;
 }


  return 0;
}
