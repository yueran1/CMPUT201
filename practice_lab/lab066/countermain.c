// test code for Counter

#include <assert.h>
#include <stdio.h>

#include "Counter.h"

int main()
{
  int T = 20;
  Counter c1(T);

  // T ticks ...
  for (int i=0; i < T; ++i) {
    printf( "tick ... %d\n", i );
    assert(!c1.done());
    c1.tick();
  }

  assert(c1.done());
  c1.tick(); // should complain
  return 0;
}
