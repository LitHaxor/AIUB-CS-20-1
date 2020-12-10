#include<iostream>

using namespace std;

// declaring
void array_input(int arr[], int size);

void swap(int arr[], int left, int right);

int *sort_array(int arr[], int size); // using bouble sort

void array_output(int arr[], int size);

int binary_search(int arr[], int start, int end, int key);


int main()
{
  cout <<"**Binary Search**" <<endl;
  int size, element;
  cout << "Enter size of the array: "; cin >> size;
  int *arr= new int[size]; // dynamic array created
  cout << "Enter array elements: ";
  array_input(arr,size);
  cout<< "\nSorted array:";
  arr = sort_array(arr,size); // passing sorted value to array arr
  array_output(arr,size);
  cout << "\nEnter element to search from array: ";
  cin >> element;



  cout << "\nElement found at " << binary_search(arr, 0, size-1, element) << " th index.";
}


// function bodies

int *sort_array(int arr[], int size)
{
  // bubble sort applied using dynamic array
  int *temp = new int [size];
  temp = arr;
  bool sorted = false;
  do {
    sorted =false;
    for(int  i=0; i < size-1 ; i++)
      {
        if( temp[i] > temp[i+1]) // checking left element is bigger then right
          {
            swap(temp, i, (i+1)); // if true then swap
            sorted = true;
          }
      }
  } while(sorted); // while all element sorted= true , break
  return temp; // returning all sorted  element
}
void swap(int arr[], int left, int right)
{
  int temp = arr[left];
  arr[left] = arr[right];
  arr[right] = temp;
}

int binary_search(int arr[], int start, int end, int key)  // passing array arr, start index, end index, key value to search
{
  int mid;
  while(end >= start) // end is bigger or equal  than start then array element is present or not empty
  {
    mid = (start+end)/2; // finding mid value avrg the start and end value
    if(arr[mid] ==  key ) // if we found key value at mid index array
      return mid; // return index number
    if(arr[mid]>key) // if mid index value is bigger than key value
      end = mid-1; // then we can exclude all bigger value then mid index
    else if(arr[mid]< key) // if mid index value is smaller than key value
      start = mid +1;  // we can exclude all smaller values than mid
  }
  return -1; // if noting is found return -1
}
void array_input(int arr[], int size)
{
  for(int i=0; i < size; i++)
    cin >> arr[i] ;
}
void array_output(int arr[], int size)
{
  for(int i=0; i < size; i++)
    cout << arr[i]  << " " ;
  cout << endl;
}
