#include<string>
#include<iostream>
using namespace std;

int main()
{
  string result;
  result=result+(char)(('z'-'a')%10+'0');
  cout<<result<<endl;
  cout<<(char)(('z'-'a')%10+'0')<<endl;



}
