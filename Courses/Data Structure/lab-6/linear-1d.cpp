#include<iostream>
using namespace std;


// declaring funcitons
int linear_search(int arr[] , int size, int key);

void array_input(int arr[], int size);


// main function

int main()
{
  cout << "** Linear Search **"<<endl;
  int size;
  cout << "Enter size of array: "; cin >> size;
  int arr[size];
  cout <<  "Enter array element: ";
  array_input(arr,size);
  cout << "\nEnter the element to Search: ";
  int element;
  cin >> element;
  cout << "element found at : " << linear_search(arr, size, element) << " th index" <<endl;
}


int linear_search(int arr[], int size, int key)
{
  for(int i=0; i < size ; i++) // loop indexing from 0 - size-1
  {
    if(arr[i] == key) // if array ith index value is same as key value
      return i; // then return i th index where we found the key value
  }
  return -1; // if not found then return -1
}


void array_input(int arr[], int size)
{
  for(int i=0; i < size ; i++)
    cin >> arr[i] ;
}
