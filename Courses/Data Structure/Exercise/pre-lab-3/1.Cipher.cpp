#include<iostream>
using namespace std;
string encode(string str, int cr)
{
  string output = "";
  for(int i=0; i< str.length() ;i++)
    {
      if(isupper(str[i]))
        output += char(int(str[i]+cr -65)%26 +65);
      else
        output += char(int(str[i]+cr-97%26 +97));
    }
    return output;

}
int main()
{
  string str; int cr;
  cout << "Enter text: "; cin >> str;
  cout << "Shift: " ; cin >> cr;
  cout << "Encrypted: " << encode(str,cr) <<endl;
}
