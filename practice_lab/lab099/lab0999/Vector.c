#include "Vector.h"
#include <cassert>

// Vector constructor: allocate elements
Vector::Vector(int N)
{
  elems = new int[N];
  n = N;
}

// destructor: free memory
Vector::~Vector()
{
  delete [] elems;
}

// return number of elements
int Vector::size() const
{
  return n;
}

// returns i-th element
int Vector::get(int i) const
{
  assert(i >= 0 && i < n);
  return elems[i];
}

// sets i-th element to v
void Vector::set(int i, int v)
{
  assert(i >= 0 && i < n);
  elems[i] = v;
}


// overloaded + operator
Vector operator+ ( const Vector & a, const Vector & b ) 
{

  assert (a.size() == b.size());

  int size = a.size();

  Vector c(size);

  for (int i = 0; i < size; i++) {
    int sum = a.get(i) + b.get(i);
    c.set(i , sum);
  }
  
  return c;
}

// overloaded * operator
int operator* ( const Vector & a, const Vector & b )
{
  assert (a.size() > 0);  // just to be safe
  assert (b.size() > 0);
  
  return a.get(0) * b.get(0);
}


// overloaded = operator
void Vector::operator= ( const Vector & a){

  assert (a.size() <= n);
  
  int size = a.size();

  for (int i = 0; i < size; i++) {
    set(i , a.get(i) );
  }
    
}


// Copy Constructor
Vector::Vector( const Vector & v){

  int size = v.size();

  n = size;    
  elems = new int[size];
  
  for (int i = 0; i < size; i++) {
    set(i , v.get(i));
  }
}

