#include<iostream>
using namespace std;
void reverse(int arr[], int start, int end){
    while(start<end)
    {
      int temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
      start++; end--;
    }
}
void marge(int arr1[], int n1,int arr2[], int n2, int arr3[])
{
  for(int i=0; i< n1; i++)
    arr3[i] = arr1[i];
  for(int i=n1; i<n1+n2; i++)
    arr3[i] = arr2[i-n1];
  reverse(arr3,0,(n1+n2)-1);
}

void print(int arr[], int n)
{
  for(int i=0;i<n;i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int t=1,n1,n2;
  while(t--)
  {
    cout << "Enter first array size: " ; cin >> n1;
    int arr1[n1];
    cout << "Array_1: ";
    for(int i=0; i< n1; i++)
      cin >> arr1[i];
    cout << "Enter second array size: " ; cin >> n2;
    cout<< "Array_2: ";
    int arr2[n2];
    for(int i=0; i< n2; i++)
      cin >> arr2[i];
    int arr3[n1+n2];
    marge(arr1,n1, arr2, n2, arr3);
    print(arr3,n1+n2);
  }
}
