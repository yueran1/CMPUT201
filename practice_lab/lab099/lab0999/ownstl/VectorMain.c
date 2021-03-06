#include<stdio.h>
#include "vectorstl.h"


void print(Vector<int> & v) {
  for(int i = 0; i < v.size(); i++){
    printf("%d ", v.get(i));
  }
  printf("\n");
}

void print(Vector<char> & v) {
  for(int i = 0; i < v.size(); i++){
    printf("%c ", v.get(i));
  }
  printf("\n");
}


int main()
{
  
  Vector<int> v1(10);   // vector of ints

  for(int i = 0; i<10; i++){
    v1.set(i, i+1);
  }
  
  print(v1);

  
  Vector<char> c(10);   // vector of chars
  
  for(int i = 0; i<10; i++){
    c.set(i, (char)(i+97));  // ASCII values converted to chars
  }

  c.set(0, 'z');

  print(c);
  

  
  /*
  Vector<int> v2(10);
  
  for(int i = 0; i<10; i++){
    v2.set(i, 10-i);
  }
  print(v2);

  Vector<int> v3(10);

  for(int i = 0; i<10; i++){
    v3.set(i, i+1);
  }
  print(v3);
  
  Vector<int> v4(10);
  v4 = v3;  // using assignment operator
  print(v4);

  Vector<int> v5 = v4;   // using copy constructor
  print(v5);
  */

  
  return 0;
}
