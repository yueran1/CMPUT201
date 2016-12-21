#include"points.h"

Points:: Points(int a)
{
  num=a;
  x=new int[num];
  y=new int[num];

}

Points:: ~Points()
{
  delete [] x;
  delete [] y;


}
