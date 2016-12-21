#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// template function for printing a vector of any type
template <typename T> void print(vector<T> & v) {

  typename vector<T>::iterator  i;

  for ( i = v.begin() ;  i != v.end() ; i++ ) {
    cout <<  *i << " ";
  }
  cout << endl;  
}



int main()
{
  
  vector<int> v(10);   // vector of ints
  
  for(int i = 0; i<10; i++){
    v[i] = i+1;
  }

  print(v);


  vector<char> c(10);   // vector of chars
  
  for(int i = 0; i<10; i++){
    c[i]= (char)(i+97);  // ASCII values converted to chars
  }

  print(c);

  
  return 0;
}
