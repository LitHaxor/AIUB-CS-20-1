#include<iostream>
using namespace std;
void Matrix_input(int arr[][4])
{
  for(int i=0;i <3; i++){
    for(int j=0; j<4; j++){
      cin >> arr[i][j];
    }
  }
}

void transpose(int arr[][4],int arr2[][3])
{
  for(int i=0; i<4; i++){
    for(int j=0; j< 3; j++){
      arr2[i][j] = arr[j][i];
    }
  }
}
void print_Matrix(int arr[][3])
{
  for(int i=0;i <4; i++){
    for(int j=0; j<3; j++){
      cout<<  arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int arr[3][4];
  int arr2[4][3];
  cout << "\nMatrix_1: \n";
  Matrix_input(arr);
  cout << "\n\n";
  cout << "Output: \n";
  transpose(arr,arr2);
  print_Matrix(arr2);
}
