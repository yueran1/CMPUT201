#include<iostream>
using namespace std;

struct Vec3
{
  int a,b,c;
  Vec3(int a1, int b1, int c1)
    {
      a=a1;
      b=b1;
      c=c1;
    }
  void print()
    {

      cout<<"a="<< a<<" ";
      cout<<"b="<< b<<" " ;
      cout<<"c="<< c<<" ";
      
    }
  void operator=(const Vec3 &rhs)
    {

      a=rhs.a;
      b=rhs.b;
      b=rhs.b;
      
    }

};

int main()
{
  Vec3 v(1,2,3);
  Vec3 w(0,0,0);
  cout << "w: ";
  w.print();
  cout << endl;
  w = v;
  cout << "v: ";
  v.print();
  cout << endl;
  cout << "w: ";
  w.print();
  cout << endl;
  
}
