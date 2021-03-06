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

/*
 * return first == nullptr 
*/
template<typename T>
bool Dlist<T> :: IsEmpty() const{
  return (first == nullptr);
}

/*
  node insert = o;

  if first == null ptr
    frist and last = insert
  else
    insert ->next = first
    first->pervious = insert 
    first = insert
*/
template<typename T>
void Dlist<T> :: InsertFront(const T& o){
  node* insert = new node;
  insert-> o = o;
  insert->prev = nullptr;
  insert -> next = nullptr;

  if(first==nullptr){
    first = insert;
    last = insert;
  }
  else{
    insert ->next = first;
    first ->prev = insert;
    first = insert;
  }
}
/*
  node insert = o;

  if first == null ptr
    frist and last = insert
  else
    insert ->next = last
    last->pervious = insert 
    last = insert
*/
template<typename T>
void Dlist<T> :: InsertBack( const T& o){
  node* insert = new node;
  insert ->o = o;
  insert->next = nullptr;
  insert->prev = nullptr;

  if(last==nullptr){
  first = insert;
  last = insert;
  }
  else{
    insert -> prev = last;
    last -> next = insert;
    last = insert;
  }
}
/*
  if empty 
    throw empty list
  else
  node* temp = first;
  T val = temp -> o ;
  first = temp->next; 
  if first == nullptr
    last = nullptr;
  else
    first->prev = nullptr;

  delete temp;
  return val;
*/

template<typename T>
T Dlist<T> :: RemoveFront(){

  if( IsEmpty() ){
    emptyList e;
    throw e;
  }
  else{
  node* temp = first;
  T val = temp -> o ;
  first = temp->next; 
  if(first == nullptr)
    last = nullptr;
  else
    first->prev = nullptr;

  delete temp;
  return val;
  }
}
/*
  if empty 
    return empty list
  else
    node* temp = new node;
    temp = last;
    T val = temp->o;
    last = temp->prev; 
    if (last == nullptr)
      first = nullptr;
    else
      last->next = nullptr;
    delete temp;
    return val;
*/
template<typename T>
T Dlist<T> :: RemoveBack(){
 
  if( IsEmpty() ){
    emptyList e;
    throw e;
  }
  else{
    node* temp = new node;
    temp = last;
    T val = temp->o;
    last = temp->prev; 
    if (last == nullptr)
      first = nullptr;
    else
      last->next = nullptr;
    delete temp;
    return val;
  }
}

/*
  first and last = nullptr
*/
template<typename T>
void Dlist<T> :: MakeEmpty(){
  first = nullptr;
  last = nullptr;
}

/*
   MakeEmpty();
*/
template<typename T>
Dlist<T> :: Dlist(){
   MakeEmpty();
}

/*
  while not empty
    node thing = first
    first = thing ->next
    deleat thing
  makeempty()
*/
template<typename T>
void Dlist<T> :: RemoveAll(){
  while( !IsEmpty() ){
    node* thing = first;
    first = thing->next; 
    delete thing; 
  }
  MakeEmpty();

}

/*
  tmep =  l.first
  while temp != nullptr
    insertback (temp->o)
    temp=temp->next
*/
template<typename T>
void Dlist<T>::CopyAll(const Dlist& l ){ 
    node* temp= l.first;
    while (temp != nullptr){
      InsertBack(temp->o);
      temp = temp->next;
    }

}

/*
  makeempty
  copyall(l)
*/
template<typename T>
Dlist<T>::Dlist(const Dlist &l){
  MakeEmpty();
  CopyAll(l);
}

/*
    if this != &l
    RemoveAll();
    CopyAll(l);
  return *this;
*/
template<typename T>
Dlist<T>& Dlist<T>::operator=(const Dlist &l){
  if(this != &l) {
    RemoveAll();
    CopyAll(l);
    }
  return *this;
}

/*
  removeall
*/
template<typename T>
Dlist<T> :: ~Dlist(){
    RemoveAll();
};




/* this must be at the end of the file */
#endif /* __DLIST_H__ */
