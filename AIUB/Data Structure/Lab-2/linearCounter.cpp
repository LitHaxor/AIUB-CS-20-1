#include<iostream>
using namespace std;

int * arrayInput(int size){
    int *arr = new int[size];
    for(int i=0; i < size; i++)
      cin >> arr[i];
    return arr;
}
void linearSearchCounter(int arr[], int size, int key)
{
  int counter=0;
  for(int i=0; i < size; i++){
    if(arr[i]== key)
      counter++;
  }
  if(counter == 0)
    {
      cout << key << " not found in array!" << endl;
      return;
    }
  cout << "The number occurs " << counter << " times in the array!" << endl;

}


int main()
{
  cout << "\nArray_1: ";
  int *arr; int key;
  arr = arrayInput(10);
  cout << "\nInput a number to search: "; cin >> key;
  linearSearchCounter(arr,10,key);

}
/*
8 4 6 1 6 9 6 1 9 8
*/
