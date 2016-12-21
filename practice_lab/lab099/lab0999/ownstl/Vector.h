#pragma once

class Vector
{
private:
  // data members hidden from users
  int *elems;
  int n;
  
public:
 
  // constructor: allocate n elements
  // called when Vector is created
  Vector(int n);

  // copy constructor
  Vector( const Vector & v);
  
  // destructor: called when Vector
  // is going out of scope or is destroyed
  ~Vector();

  // returns number of elements (no change)
  int size() const;

  // returns i-th element (no change)
  int get(int i) const;

  // sets i-th element to v
  void set(int i, int v);

  // overloaded assignment operator =
  void operator= (const Vector & a);
};


// overloaded + operator
// note that this is not a member function of the class
extern Vector operator+ ( const Vector & a, const Vector & b );

// overloaded * operator
extern int operator* ( const Vector & a, const Vector & b );
