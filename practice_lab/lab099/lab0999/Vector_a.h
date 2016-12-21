#pragma once

#include <assert.h>

template <typename T>
class Vector
{
private:
  // data members hidden from users
  T *elems;
  int n;
  
public:
 
  // constructor: allocate n elements
  // called when Vector is created
  Vector(int N);

  // copy constructor
  Vector( const Vector & v);
  
  // destructor: called when Vector
  // is going out of scope or is destroyed
  ~Vector();

  // returns number of elements (no change)
  int size() const;

  // returns i-th element (no change)
  T get(int i) const;

  // sets i-th element to v
  void set(int i, T v);

  // overloaded assignment operator =
  void operator= (const Vector & a);
};



// Vector constructor: allocate elements
template <typename T>
Vector<T>::Vector(int N)
{
  elems = new T[N];
  n = N;
}

// destructor: free memory
template <typename T>
Vector<T>::~Vector()
{
  delete [] elems;
}

// return number of elements
template <typename T>
int Vector<T>::size() const
{
  return n;
}


// sets i-th element to v
template <typename T>
void Vector<T>::set(int i, T v)
{
  assert(i >= 0 && i < n);
  elems[i] = v;
}

// returns i-th element
template <typename T>
T Vector<T>::get(int i) const
{
  assert(i >= 0 && i < n);
  return elems[i];
}


// overloaded = operator
template <typename T>
void Vector<T>::operator= ( const Vector & v){

  assert (v.size() <= n);
  
  int size = v.size();

  for (int i = 0; i < size; i++) {
    set(i , v.get(i) );
  }
    
}


// Copy Constructor
template <typename T>
Vector<T>::Vector( const Vector & v){

  int size = v.size();

  n = size;    
  elems = new T[size];
  
  for (int i = 0; i < size; i++) {
    set(i , v.get(i));
  }
}
