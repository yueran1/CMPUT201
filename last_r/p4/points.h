#pragma once

using namespace std;
template <typename T> class Points
{
public:
  T *x;
  T *y;
  int num;

  Points(int a)
    {
      num=a;
      x=new T[num];
      y=new T[num];
    }
  ~Points()
    {

    delete [] x;
    delete [] y;
    }
};
