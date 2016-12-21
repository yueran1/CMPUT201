#include"points.h"

Points::Points(int i)
{
  num=i;
  x=new int[num];
  y=new int[num];
}

Points:: ~Points()
{
  delete [] x;
  delete [] y;
}
