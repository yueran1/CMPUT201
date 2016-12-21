#include<string>
#include<iostream>
using namespace std;

int main()
{
  string result;
  string s;
  cin>>s;
  for (unsigned int i=0; i<s.size(); i++)
  {
    if(s[i]>='a' && s[i]<='z')
    {
      result =result+(char)((s[i]-'a')%10 +'0');
    }
    else
    {
      result=result+s[i];
    }

    cout<<result<<endl;
  }
}
