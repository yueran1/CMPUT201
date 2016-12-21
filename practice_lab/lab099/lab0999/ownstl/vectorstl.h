# pragma once
# include<assert.h>

template <typename T> class Vector
{
private:
  T *elems;
  int n;
public:
   Vector(int N)
    {
      elems= new T [N];
      n=N;
    }
  ~Vector()
    {
      delete [] elems;
    }
  int size() const
    {
      return n;
    }

  T get(int i) const
    {
      assert(i>=0 && i<n);
      return elems[i];
    }
  void set(int i, T v) const
    {
      assert(i>=0 && i<=n);
      elems[i]=v;
    }
  
  void operator=(const Vector &a)
    {
      assert(a.size()<=n);
      int size= a.size();
      for (int i=0; i<size; i++)
      {
        set (i, a.get(i));
      }
    }

  Vector(const Vector &v)
    {
      assert(v.size()>=0 && v.size()<=n);
      int size=v.size();
      n=size;
      elems =new T[size];
      for (int i=0; i<size; i++)
      {
        elems[i]=v.get(i);
      }
    }
};
