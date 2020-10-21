#include<iostream>
using namespace std;
void margeArray(int arr1[],int n1, int arr2[], int n2, int arr3[]){
  int i=0,j=0,k=0;
  while(k<n1){
    arr3[k++] = arr1[j++];
  }
  int n = n1+n2;
  while(k< n)
    {
      arr3[k++] = arr2[i++];
    }
}
void reversePrint(int arr[], int size){
  for(int i=size-1; i>=0;i--)
    cout << arr[i] << " ";
}

int main()
{
  int arr1[] = {10,20,30,40,50};
  int n1 = sizeof(arr1)/sizeof(arr1[0]);
  int arr2[] = {1,2,3,4,5,6,7,8};
  int n2 = sizeof(arr2)/sizeof(arr2[0]);
  int arr3[n1+n2];
  cout << "\nOutput:\n";
  margeArray(arr1,n1,arr2,n2,arr3);
  reversePrint(arr3,n1+n2);
}
