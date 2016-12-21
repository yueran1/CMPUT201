#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s;
  string result;
  //scanf("%s", s);
  cin>>s;
  for (int i=0;i<s.size();i++)
  {
    if(s[i]>='a'  && s[i]<='z')
    {
      result=result+(char)((s[i]-'a')%10+'0');
    }

    else
    {
      result=result+s[i];
    }
  }
  cout<<result<<endl;
}
