#include <iostream>
using namespace std;

template <typename T>
struct Vec3
{

  Vec3(T a_,T b_, T c_)
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
  T a,b,c;
};



int main()
{
  {
    Vec3<double> v(1.5, 2.5, 3.5), w(0, 1, 2);
    cout << "w: ";
    w.print();
    cout << endl;

    w = v;
    cout << "v: ";
    v.print();
    cout << endl;
    cout << "w: ";
    w.print();
  }
  {
    Vec3<int> v(1, 2, 3), w(4, 5, 6);
    cout << "w: ";
    w.print();
    cout << endl;

    w = v;
    cout << "v: ";
    v.print();
    cout << endl;
    cout << "w: ";
    w.print();
  }
}
