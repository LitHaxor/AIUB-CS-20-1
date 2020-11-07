#include<iostream>
using namespace std;

void printArray(int arr[], int size);
void swap(int arr[], int fi , int si, int d);

void leftRotate(int arr[], int d, int n)
{
  if(d == 0 || d ==n)
    return;
  if(n - d == d)
  {
    swap(arr, 0, n-d, d);
    return;
  }
  if(d < n - d )
  {
    swap(arr,0, )
  }
}

int main()
{

}
