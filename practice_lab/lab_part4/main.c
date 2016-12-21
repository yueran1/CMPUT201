#include "vector.h"
#include "cstdio"

int main()
{
  const int N= 100000;
  Vector v(N); //vector created on stack
  v.n=5; // illegal, n is private
  // set elements
  for (int i=0; i<N; ++i)
  {
    v.set(i, 2*i);
    
  }
  //print them
  for (int i=0; i<N; ++i)
  {
    printf("%d \n", v.get(i));
  }
  // vector v goes out of scope=> its destructor
  // is called, freeing memory automatically.
  return 0;
}
