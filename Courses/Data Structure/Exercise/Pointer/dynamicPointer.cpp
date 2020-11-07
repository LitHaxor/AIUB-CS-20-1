#include<iostream>
using namespace std;

int main()
{
  int *ptr = NULL;
  int array[50];
  ptr  = array;
  ptr[0] = 0;
  cout << ptr[0];
  return 0;
}
