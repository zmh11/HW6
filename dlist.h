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

  bool isEmpty() const;
  // EFFECTS: returns true if list is empty, false otherwise

  void insertFront(const T &o);
  // MODIFIES this
  // EFFECTS inserts o at the front of the list
    
  void insertBack(const T &o);
  // MODIFIES this
  // EFFECTS inserts o at the back of the list

  T removeFront();
  // MODIFIES this
  // EFFECTS removes and returns first object from non-empty list
  //         throws an instance of emptyList if empty

  T removeBack();
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
bool Dlist<T> :: isEmpty() const{
  return (first == NULL);
}

template<typename T>
void Dlist<T> :: insertFront(const T& k){
  node* insert = new node;
  insert-> o = k;
  insert->prev = NULL;
  insert -> next = NULL;

  if(isEmpty()){
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
void Dlist<T> :: insertBack( const T& k){
  node* insert = new node;
  insert ->o = k;
  insert->next = NULL;
  insert->prev = NULL;

  if(isEmpty()){
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
T Dlist<T> :: removeFront(){

  node* temp = first;
  T val = temp -> o ;
  first = first-> next;
  delete temp;
  return val;
}

template<typename T>
T Dlist<T> :: removeBack(){
  if( isEmpty() ){
    std::cerr << "Error: list is empty\n";
    assert(0);
  }
  node* temp = last;
  T val = temp -> o;
  last = last->prev;
  delete temp;
  return val;
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
  int temp;
  while( !isEmpty() ){
    temp = RemoveFront();
  }
}

template<typename T>
Dlist<T> :: ~Dlist(){
    RemoveAll();
};




/* this must be at the end of the file */
#endif /* __DLIST_H__ */
