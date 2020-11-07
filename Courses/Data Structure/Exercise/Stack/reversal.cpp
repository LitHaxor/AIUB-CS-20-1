#include<iostream>
using namespace std;
string array_reversal(string str)
{
  string temp;
  for(int i=str.length()-1; i>=0; i--)
    temp += str[i];
  return temp;
}
int  main()
{
  string str="hello";
  cout <<   array_reversal(str) << endl;
  return 0;
}
