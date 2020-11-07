#include<iostream>
using namespace std;

struct Student {
    int Uid;
    string name;
    int credits_completed;
    float cgpa;
};
void printInfo(Student students)
{

}
int main()
{
  int n;
  cout << "Enter number of students: ";
  cin >> n;
  struct Student students[n];
  int t=0 , i= 0;
  while(t<n)
  {
    students[i].Uid =++t;
    cout << "Student ID: "<< t <<endl;
    cout << "Enter name: " ;
    cin >> students[i].name;
    cout <<t << ".Credit: ";
    cin >> students[i].credits_completed;
    cout << t <<".CGPA:";
    cin >> students[i].cgpa;
    i++;
    cout << endl;
  }
  cout << "Printing all the student ID whose CGPA is more than 3.75." << endl;
  i=0;
  while(i < n)
  {
    if(students[i].cgpa> 3.75 )
      cout << "UID: " << students[i].Uid <<"\tName:"<< students[i].name << endl;
      i++;
  }
  cout << endl;
  cout << "Printing all the student ID whose Credit is more than 50 ." << endl;
  i=0;
  while(i < n)
  {
    if(students[i].credits_completed> 50 )
      cout << "UID: " << students[i].Uid <<"\tName:"<< students[i].name << endl;
      i++;
  }
}
