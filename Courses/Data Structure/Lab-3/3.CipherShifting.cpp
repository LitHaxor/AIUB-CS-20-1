#include<iostream>
#include<string>
using namespace std;
int encoder(char ch, int s);
string cipherShift(string str, int s)
{
  string encode ="";
  for(char ch: str)
    {
      if((int) ch == 32)
       encode += (char) 32;
     else
      encode +=  (char) encoder(ch,s);
    }
  return encode;
}

int encoder(char ch, int s)
{
  int a=  (int) ch;
  if(65 <= a && a <= 90)
    return (((a+s)-65)%26 +65);
  else if(97 <= a && a <= 122)
    return (((a+s)-97)%26 +97);
  return -1;
}

int main()
{
    string str; int s;
    cout << "Enter String:";
    getline(cin,str);
    cout << "Enter shift: "; cin>> s;
    cout << "Encode: " << cipherShift(str,s);
}
