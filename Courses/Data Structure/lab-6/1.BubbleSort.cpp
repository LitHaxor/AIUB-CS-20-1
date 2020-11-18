#include<iostream>
using namespace std;

void Array_Input(int arr[], int size);

void Array_output(int arr[], int size);

void swap(int arr[], int i, int j);

void bubbleSort (int arr[], int size);

int main()
{
  int size;
  cout << "Enter array size:" ;
  cin >> size;
  int arr[size];
  Array_Input(arr, size);
  cout << "sorted array:";
  bubbleSort(arr, size);
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

void bubbleSort(int arr[],int size)
{
  bool sorted = false;
  do {
    sorted =false;
    for(int  i=0; i < size-1 ; i++)
      {
        if( arr[i] > arr[i+1])
          {
            swap(arr, i, (i+1));
            sorted = true;
          }
      }
  } while(sorted);
}

void swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
