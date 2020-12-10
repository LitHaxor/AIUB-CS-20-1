#include<iostream>
using namespace std;
//declaration of function
void Array_Input(int arr[], int size);

void Array_output(int arr[], int size);

void swap(int arr[], int i, int j);

void bubbleSort (int arr[], int size);


// main fucntion
int main()
{
  int size;
  cout << "Enter array size:" ;
  cin >> size;
  int arr[size]; // declaring array size
  cout << "Enter Array elements: ";
  Array_Input(arr, size); // taking input
  cout << "sorted array:";
  bubbleSort(arr, size); // applying bubbleSort array arr and size =size
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
  bool sorted = false; // delcaring array is sorted =false
  do {
    sorted =false; // for everylop sorted = false
    for(int  i=0; i < size-1 ; i++) // for loop iterating 0 to size -1
      {
        if( arr[i] > arr[i+1]) // if left element (i) is bigger then right (i+1)
          {
            swap(arr, i, (i+1)); // then swap left with right
            sorted = true; // if element is sorted make it true
          }
      }
  } while(sorted); // while every element is sorted =true loop breaks
}

void swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
