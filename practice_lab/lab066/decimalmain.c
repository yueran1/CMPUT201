// test code for Decimal
#include <stdio.h>
#include "decimal.h"

int main()
{
  // some test cases
  if (0) {
    decimal d(4);
    d.set(10000); // overflow
  }
  
  if (1) {
    decimal d(6), e(6);
    d.set(199999);
    e.set(1);
    d.add(e);
    d.print(); // should be 200000
    printf("\n");
    
    d.add(d); // 400000
    d.print(); 
    printf("\n");

    d.add(d); // 800000
    d.print(); 
    printf("\n");

    d.add(d); // overflow
    d.print(); 
    printf("\n");
  }

  return 0;
}
