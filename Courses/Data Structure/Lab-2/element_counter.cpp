#include<iostream>
using namespace std;
int * arrayInput(int size){
    int *arr = new int[size];
    for(int i=0; i < size; i++)
      cin >> arr[i];
    return arr;
}

void elementCounter(int arr[], int size)
{
   int checked[size];
  for(int i=0;i < size;i++){
    checked[i] = 0;
  }
  for(int i=0 ; i < size; i++){
    if(checked[i] == 1)
      {
        continue;
      }
      int count =1;
    for(int j=i+1; j< size ; j++)
    {
      if(arr[i] == arr[j]){
        count++;
        checked[j]= 1;
      }
    }
    cout << arr[i] << " occurs = "<< count << " times!"<< endl;
  }
}



int main()
{
  int *arr;
  cout << "\n\nArray_1 = ";
  arr = arrayInput(10);

  cout << "Output: "<< endl;
  elementCounter(arr, 10);
  return 0;
}
