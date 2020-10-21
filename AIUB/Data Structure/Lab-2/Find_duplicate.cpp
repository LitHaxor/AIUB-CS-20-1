#include<iostream>
using namespace std;
void findDuplicate(int arr[],int n)
{
  int i,j,k=0,count =0, check=0;
  for(i=0; i< n; i++){
    k=i;
    for(j=i+1; j< n; j++)
    {
      if(arr[i]!= arr[j]){
        arr[++k] = arr[j];
      }
      else{
        count++;
        check++;
      }
    }
    n -= count;
    count = 0;
  }
  if(check == 0){
    cout << "Output: Array is unique!";
  }
  else {
    cout << "Output: ";
    for(i=0;i<n;i++)
    {
      cout  << arr[i] << " ";
    }
    cout << endl;
  }
}


int nScenario =0;


int *createArray(int size)
{
  int *arr = new int[size];
  cout << "\nScenario " << ++nScenario << ": "<<endl;
  cout << "Array_" << nScenario << ":" ;
  for(int i=0; i< size; i++){
    cin >> arr[i];
  }
  return arr;
}
int main()
{
  int *arr1;
  arr1 = createArray(7);
  findDuplicate(arr1,7);
  int *arr2;
  arr2 = createArray(6);
  findDuplicate(arr2,6);

}
/*
arr1 = 1 4 6 3 6 9 1
arr2 = 1 4 5 3 6 9
 */
