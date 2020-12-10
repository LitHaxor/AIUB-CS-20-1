#include<iostream>
using namespace std;


//declaring fucntion
void array_input(int arr[], int size);

void insertion_sort(int arr[], int size);

void Array_output(int arr[], int size);


// main fucntion
int main()
{
  cout << "**Insertion sort**"<<endl;
  int size;
  cout << "Enter size of the array: "; cin >> size;
  int arr[size];
  cout << "Enter array elements: ";
  array_input(arr,size);
  cout << "Sorted array: ";
  insertion_sort(arr, size);
  Array_output(arr,size);
}


void array_input(int arr[], int size)
{
  for(int i=0; i < size; i++)
    cin >> arr[i] ;
}

void insertion_sort(int arr[], int size)
{
  bool moved =false; // declaring flag, which determines the position of instetion array needs to changed/inserted
  int extract =0,i=0,j=0; // decalaring sorted , i,j
  // set 0 th index as sorted
  for(i=1; i < size  ; i++) // loop iterates through unsorted element.
  {
    extract = arr[i]; // extract the next i th (unsorted) element

    for(j=i-1; j>=0 ;j--) // loop iterates through all sorted elements
    {
      if( arr[j] >  extract) // if extracted element is bigger then jth array(sorted elements)
      {
        arr[j+1] = arr[j]; //  move sorted element to the right by 1
        moved = true; // set flag true
      }

      else // if it not , then break the loop
        break;
    }
    if(moved) // if the element is moved
      arr[j+1] = extract; // then insert the element at it's postion (j+1)
  }
}

void Array_output(int arr[], int size)
{
  for(int i=0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
