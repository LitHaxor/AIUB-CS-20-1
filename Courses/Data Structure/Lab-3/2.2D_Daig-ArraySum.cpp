#include<iostream>
using namespace std;
#define SIZE 5
int sumArray(int arr[][SIZE])
{
  int sum = 0;
  for(int i=0; i < SIZE ; i++)
    for(int j=0; j< SIZE; j++)
      if( i== j || (i+j) == (SIZE-1))
          sum += arr[i][j];
  return sum;
}
void ArrayIn(int arr[][SIZE])
{
  for(int i=0; i < SIZE ; i++)
    for(int j=0; j< SIZE; j++)
      cin >> arr[i][j];
}

int main()
{
    int arr[SIZE][SIZE];
    cout << "Matrix_1: "<< endl;
    ArrayIn(arr);
    cout << "Summation is: " << sumArray(arr) << endl;
}

/*
  a00 a01 a02 a03
  a10 a11 a12 a13
  a20 a21 a22 a23
  a30 a31 a32 a33
1    2     3    4   5
14   15   16   17   6
13   1    19    18  7
12   11   10    9   8
21   22   23   24  25


  a00 + a11 + a22 + a33 i == j
  a30 + a21 + a12 + a03 i+j == 3

 */
