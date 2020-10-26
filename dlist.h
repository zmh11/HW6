#ifndef __DLIST_H__
#define __DLIST_H__


/***************************************
 * Do not modify the class declarations!
 ***************************************/
class emptyList {
  // OVERVIEW: an exception class
};

template <typename T>
class Dlist {
  // OVERVIEW: contains a double-ended list of Objects

 public:

  // Operational methods

  bool IsEmpty() const;
  // EFFECTS: returns true if list is empty, false otherwise

  void InsertFront(const T &o);
  // MODIFIES this
  // EFFECTS inserts o at the front of the list
    
  void InsertBack(const T &o);
  // MODIFIES this
  // EFFECTS inserts o at the back of the list

  T RemoveFront();
  // MODIFIES this
  // EFFECTS removes and returns first object from non-empty list
  //         throws an instance of emptyList if empty

  T RemoveBack();
  // MODIFIES this
  // EFFECTS removes and returns last object from non-empty list
  //         throws an instance of emptyList if empty

  // Maintenance methods
  Dlist();                                   // ctor
  Dlist(const Dlist &l);                     // copy ctor
  Dlist &operator=(const Dlist &l);          // assignment
  ~Dlist();                                  // dtor

 private:
  // A private type
  struct node {
    node   *next;
    node   *prev;
    T      o;
  };

  node   *first; // The pointer to the first node (0 if none)
  node   *last;  // The pointer to the last node (0 if none)
  //How us this different than the doubly linked list in class?

  // Utility methods

  void MakeEmpty();
  // EFFECT: called by constructors to establish empty
  // list invariant
    
  void RemoveAll();
  // EFFECT: called by destructor and operator= to remove and destroy
  // all list nodes

  void CopyAll(const Dlist &l);
  // EFFECT: called by copy constructor/operator= to copy nodes
  // from a source instance l to this instance
};

/**** DO NOT MODIFY ABOVE THIS LINE *****/

/***************************************
 *ADD  Member function implementations here
 ***************************************/

template<typename T>
bool Dlist<T> :: IsEmpty() const{
  return (first == NULL);
}

template<typename T>
void Dlist<T> :: InsertFront(const T& k){
  node* insert = new node;
  insert-> o = k;
  insert->prev = NULL;
  insert -> next = NULL;

  if(IsEmpty()){
    first = insert;
    last = insert;
  }
  else{
    insert ->next = first;
    first ->prev = insert;
    first = insert;
  }
}

template<typename T>
void Dlist<T> :: InsertBack( const T& k){
  node* insert = new node;
  insert ->o = k;
  insert->next = NULL;
  insert->prev = NULL;

  if(IsEmpty()){
  first = insert;
  last = insert;
  }
  else{
    insert -> prev = last;
    last -> next = insert;
    last = insert;
  }
}

template<typename T>
T Dlist<T> :: RemoveFront(){

  if( IsEmpty() ){
    //std::cerr <<"List is empty \n";
    //assert(false);
    Dlist* e = new Dlist;
    throw e;
  }
  else{
  node* temp = new node;
  temp = first;
  T val = temp -> o ;
  first = first-> next;
  // 1 value 
  if(first == NULL)
    last = NULL;
  //delete temp;
  free(temp);
  return val;
  }
}

template<typename T>
T Dlist<T> :: RemoveBack(){
 
  if( IsEmpty() ){
    //std::cerr <<"List is empty \n";
    //assert(false);
    Dlist* e = new Dlist;
    throw e;
  }
  else{
 
    node* temp = new node;
    temp = last;
    T val = temp->o;
    last = last->prev;
    //1 value
    if (last == NULL)
      first = NULL;
    
    free( temp);
    return val;
  }
}

template<typename T>
void Dlist<T> :: MakeEmpty(){
  first = NULL;
  last = NULL;
}

template<typename T>
Dlist<T> :: Dlist(){
   MakeEmpty();
}

template<typename T>
void Dlist<T> :: RemoveAll(){
  T temp;
  while( !IsEmpty() ){
    temp = RemoveFront();
  }

}

template<typename T>
Dlist<T> :: ~Dlist(){
    RemoveAll();
};




/* this must be at the end of the file */
#endif /* __DLIST_H__ */
