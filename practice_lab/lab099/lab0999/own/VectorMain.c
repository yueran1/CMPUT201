#include "Vector.h"
#include <stdio.h>

void print(Vector & v) {
  for(int i = 0; i < v.size(); i++){
    printf("%d ", v.get(i));
  }
  printf("\n");
}


int main()
{
  
  Vector v1(10);

  for(int i = 0; i<10; i++){
    v1.set(i, i+1);
  }
  print(v1);

  
  Vector v2(10);
  
  for(int i = 0; i<10; i++){
    v2.set(i, 10-i);
  }
  print(v2);


  

  Vector v3(10);

  for(int i = 0; i<10; i++){
    v3.set(i, i+1);
  }
  print(v3);
  
  Vector v4(10);

  v4 = v3;
  print(v4);

  
  Vector v5 = v4;
  print(v5);
  
  return 0;
}
