#include<iostream>
using namespace std;

struct Student {
  int bengali, english, math, science;
};
double find_average(Student std);
int main()
{
  int t =4;
  Student student[t];
  for(int i =0 ; i < t ; i++)
  {
    cout << "Give input for student " << i+1<<": ";
    cin >> student[i].bengali;
    cin>> student[i].english;
    cin >> student[i].math;
    cin>> student[i].science;
  }
  for(int i =0; i < t; i++)
  {
   cout << "Avarage number of student " << i+1<< " : " <<  find_average(student[i])<<endl;
  }
}

double find_average(Student std)
{
  double sum ;
  sum = std.bengali + std.english + std.math + std.science;
  return (double)(sum/4);
}
