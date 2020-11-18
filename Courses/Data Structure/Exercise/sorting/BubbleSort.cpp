#include<iostream>
using namespace std;
void swap(int arr[], int i, int j);
void BubbleSort(int arr[], int n);
void getArray(int arr[], int n);
void printall(int arr[],int n);
int main()
{
  int n;
  cout << "Enter number of elements: " ; cin>> n;

  int arr[n] ;
  getArray(arr,n);
  BubbleSort(arr,n);
  printall(arr,n);
  return 0;
}

void getArray(int arr[], int n)
{
  for(int i=0; i < n ; i++)
    cin >> arr[i];
}

void swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void BubbleSort(int arr[], int n)
{
  bool swapped = false;
  do {
    swapped = false;
    for( int i=0 ; i < n -1 ; i++ )
      if( arr[i] > arr[i+1] )
      {
        swap( arr, i, (i+1) );
        swapped = true;
      }
  } while(swapped);
}
void printall(int arr[], int n)
{
 for(int i =0; i < n; i++)
    cout << arr[i] << " ";
}
