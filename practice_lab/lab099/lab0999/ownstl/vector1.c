#include "Vector.h"
#include <cassert>
Vector::Vector(int N)
{
  elems= new int [N];
  n=N;
}

Vector:: ~Vector()
{
  delete [] elems;
}

int Vector::size() const
{
  return n;
}

int Vector:: get(int i) const
{
  return elems[i];
}

void Vector:: set(int i, int v)
{
  assert(i>=0 && i<n);
  elems[i]=v;
}

void Vector:: operator=(const Vector &a)
{
  assert(a.size()<=n);
  int size=a.size();
  
  for (int b=0; b < size; b++)
  {
    set(b,a.get(b));
  }
}

Vector:: Vector(const Vector &v)
{
  assert(v.size()<=n);
  int size=v.size();
  n=size;
  for (int i=0; i<size;i++)
  {
    set(i,v.get(i));
  }
}
