#include<iostream>
using namespace std;

void Array_Input(int arr[], int size);

void swap(int arr[], int i, int j);

void sort_array(int arr[],int size);

int binary_search(int arr[], int low, int high,int key);

void Array_output(int arr[], int size);


int main()
{
    int size, item;
    cout << "Enter array size: "; cin >> size;
    int arr[size];
    cout << "Enter array element: ";
    Array_Input(arr, size);
    cout << "\nSorted array:";
    sort_array(arr,size);
    Array_output(arr, size);
    cout<< endl;
    cout<< "Enter items to search in Array: ";
    cin >> item;
    cout << "\nItem found at " <<  binary_search(arr, 0, (size-1), item) << " th index.\n";

}

void Array_Input(int arr[], int size)
{
  for(int i=0; i < size; i++)
    cin >> arr[i] ;
}

void Array_output(int arr[], int size)
{
  for (int i=0; i < size; i++)
    cout << arr[i] << " ";
}
void swap(int arr[], int i ,int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void sort_array( int arr[], int size)
{
  bool sorted= false;
  do {
    sorted = false;
    for ( int  i=0; i < size-1; i++)
    {
      if(arr[i] > arr[i+1])
        {
          swap(arr, i , (i+1));
          sorted = true;
        }
    }
  } while(sorted);
}

int binary_search(int arr[], int low, int high, int key)
{
   if( high >= low)
   {
     int mid = (low + high)/2;

     if(arr[mid] == key)
      return mid;

     if( arr[mid] > key)
      binary_search(arr, low , (mid-1), key);

     if(arr[mid] < key)
      binary_search(arr,(mid+1), high, key);

   }
  return -1;

}
