#include "vector.h"
#include <cassert>

//vector constructor: allocate elements
//vector:: denotes the class context
// we implement functions for

vector:: vector(int N)
{
  elems= new int[N];
  n=N;
}

//destructor; free memory
vector:: ~vector()
{
  delete [] elems;
}

// return number of elements
int vector:: Size() const
{
  return n;
}

// return i-th element
int vector::get(int i) const
{
  assert(i>=0 && i<n);
  return elems[i];
}

// sets i-th element to v
void vector:: set(int i, int v)
{
  assert(i>=0 && i<n);
  elems[i]=v;
}
