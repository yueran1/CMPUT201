#include <iostream>
using namespace std;
struct Vec3
{

  Vec3(int a_,int b_, int c_)
    {
      a=a_;
      b=b_;
      c=c_;
    }
  void print()
    {
      cout<< "a=" << a;
      cout<<"b=" << b;
      cout <<"c="<< c;
      cout<< endl;
    }
  void operator=(const Vec3&rhs)//rhs=right hand side
    {
      a=rhs.a;
      b=rhs.b;
      c=rhs.c;
    }
  int a,b,c;
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
