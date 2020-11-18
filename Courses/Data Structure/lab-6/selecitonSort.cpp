#include<iostream>
using namespace std;

void Array_Input(int arr[], int size);

void Array_output(int arr[], int size);

void selectionSort (int arr[], int size);

void swap(int arr[], int i, int j);

int main()
{
  int size;
  cout << "Enter array size:" ;
  cin >> size;
  int arr[size];
  Array_Input(arr, size);
  cout << "sorted array:";
  selectionSort(arr, size);
  Array_output(arr,size);

}


void Array_Input(int arr[], int size)
{
  for(int i =0 ; i < size; i++)
    cin >> arr[i];
}

void Array_output(int arr[], int size)
{
  for (int i=0; i < size; i++)
    cout << arr[i] << " ";
}

void selectionSort(int arr[], int size)
{
  int min =0 ;
  for(int i=0; i< size-1; i++)
  {
    min = i;
    for(int j=i+1 ; j< size; j++)
      if(arr[j] < arr[min])
        min = j;
    if(min != i)
      swap(arr,min, i);
  }
}

void swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
