#pragma once

class vector
{
private:
  // data members hidden from users
  int *elems;
  int n;
public:
  //user accesible member functions
  //constructoe: allocate n elements
  // called when vector is created
  vector(int n);
  //destructor: called when vector
  // is going out of scope or is destoryed

  ~vector();
  // return i-th element(no change)
  int size() const;
  // retuns i-th element (no change)
  int get(int i) const;
  // sets i-th element to v
  void set(int i, int v);
};
