#include<iostream>
using namespace std;

// declaring neccesary function
void Array_Input(int arr[], int size);

void Array_output(int arr[], int size);

void selectionSort (int arr[], int size);

void swap(int arr[], int i, int j);


// main fucntion
int main()
{
  int size;
  cout << "** Selection Sort **" <<endl;
  cout << "Enter array size:" ;
  cin >> size;
  int arr[size]; //declaring array arr size of size.
  cout << "Enter Array Item: ";
  Array_Input(arr, size);
  cout << "sorted array:";
  selectionSort(arr, size); // applying selection sort to array arr and size= size.
  Array_output(arr,size);

}

// writting function body
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
  int min =0 ; // delcaring minimum index
  for(int i=0; i< size-1; i++) // loop indexing from 0 - size -1
  {
    min = i; // setting first element/ index in the loop (i) as unsorted minimum
    for(int j=i+1 ; j< size; j++) // second loop starts from 1 element right from i.
      if(arr[j] < arr[min]) // checking with jth index value is bigger then min
        min = j; // if true, then upadate min index with j index
    if(min != i) // checking , if min index is not the i index itself
      swap(arr,min, i); // if true then, then swap minimum index with i index value
  }
}

void swap(int arr[], int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
