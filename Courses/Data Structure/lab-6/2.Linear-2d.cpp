#include<iostream>
using namespace std;
#define COL 3
#define ROW 3


int LinearSearch(int arr[], int key, int size);

void LinearSearch2d ( int arr[][COL], int key );

void Array_Input_1D(int arr[], int size);

void Array_Input_2D(int arr[][COL]);

int main()
{
  int size, item;
  cout << "1D array Size:"; cin >> size;
  int arr[size];
  cout << "Enter array elements: ";
  Array_Input_1D(arr, size);
  cout << "\n\nEnter a item to search in the array:" ;
  cin >> item;
  cout << item << " Found at " <<  LinearSearch(arr, item, size) << " index.\n";

  cout << "2D Array fixed 3x3:" << endl;
  int arr2[ROW][COL];
  cout << "Enter 2d array elements (3x3):" << endl;
  Array_Input_2D(arr2);
  cout << "\n\nEnter element to search from the array: " ;
  cin >> item;
  cout << "\nItem found at:\n";
  LinearSearch2d(arr2, item);
}

int LinearSearch(int arr[], int key, int size)
{
  for ( int i=0; i< size; i++)
    {
      if( arr[i] == key)
        return i;
    }
  return -1;
}

void LinearSearch2d ( int arr[][COL], int key)
{
  for(int i=0 ; i < ROW ; i++)
    for( int  j=0 ;  j < COL ;  j++)
        if( arr[i][j] == key )
          cout << "ROW:" << i << " COL: " << j << endl;
}

void Array_Input_1D (int arr[], int size)
{
  for(int i=0 ; i< size ; i++)
    cin >> arr[i];
}

void Array_Input_2D ( int arr[][COL] )
{
  for ( int i = 0 ;  i < ROW ; i++)
    for ( int j =0 ; j < COL ; j++)
        cin >> arr[i][j];
}
