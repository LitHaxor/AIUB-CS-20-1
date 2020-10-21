#include<iostream>
using namespace std;
void common_Array(int arr1[], int n1, int arr2[], int n2)
{
  int count =0;
  for(int i =0; i < n1 ; i++)
    for(int j=0; j< n2; j++)
      if(arr1[i] == arr2[j])
         count++;


   if(count == 0){
      cout << "No common element!" << endl;
      return;
    }

    int *arr3 = new int[count];
    int k=0;
    for(int i =0 ; i< n1; i++)
     for(int j = 0; j<n2; j++)
       if(arr1[i] == arr2[j])
          arr3[k++] = arr1[i];


     for(int i=0 ; i < count-1; i++)
       cout << arr3[i] <<  " ";
}

int main()
{

  int arr_1[] = {1,4,6,3,6,9};
  int n1 = sizeof(arr_1)/sizeof(arr_1[0]);

  cout << "\n\nScenario 1:\n";
  int arr_2[] = {5,3,7,1,2,6};
  int n2 = sizeof(arr_2)/sizeof(arr_2[0]);
  cout << "output:" << endl;

  common_Array(arr_1, n1, arr_2, n2);

  cout << "\n\nScenario 2:\n";
  int arr_3[] = {5,8,7,12,21,63};
  int n3 = sizeof(arr_3)/sizeof(arr_3[0]);
  cout << "Output: " << endl;

  common_Array(arr_1, n1, arr_3, n3);
}
