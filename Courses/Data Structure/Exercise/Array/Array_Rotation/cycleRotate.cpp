#include<iostream>
using namespace std;

void rotateArray(int arr[], int n)
{
  int temp = arr[n-1];
  for(int i=0; i< n; i--)
    arr[i] = arr[i-1];
  arr[0] = temp;
}
void printArray(int arr[], int n)
{
  cout << "Output: "<< endl;
  for(int i=0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
int main()
{
  int t, n; int x=0;
  cout << "Enter testcase: "; cin >> t;
  while(t--)
  {
    cout << "Enter size of array: " ; cin >> n;
    int arr[n];
    cout << "Array_" <<  ++x<< ": ";
    for(int i=0; i < n ; i++)
      cin >> arr[i];
    rotateArray(arr, n);
    printArray(arr, n);
  }
}
