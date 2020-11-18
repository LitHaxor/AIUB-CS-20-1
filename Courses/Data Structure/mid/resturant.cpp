#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Resturant {
  queue <int> token;
  stack <int> archive;
  int TOKEN;
public:
  Resturant(){
    TOKEN=0;
  }

  void generateToken()
  {
    TOKEN++;
    token.push(TOKEN);
    cout << "Token :" << token.back() << " has been genereated!" <<endl;
  }

  void archiveToken()
  {

    cout << "Token: " << token.front() << " has been served!" << endl;
    archive.push(token.front());
    token.pop();
  }

  void show()
  {
    cout << "Archived tokens: " << endl;
    while(!archive.empty())
    {
      cout << archive.top()  << " " ;
      archive.pop();
    }
  }
};
int main()
{
  Resturant r;
  r.generateToken();
  r.archiveToken();
  r.generateToken();
  r.generateToken();
  r.archiveToken();
  r.archiveToken();
  r.generateToken();
  r.archiveToken();
  r.generateToken();
  r.generateToken();
  r.archiveToken();
  r.archiveToken();
  r.show();
}
