#include<iostream>
using namespace std;
#define COL 5
#define ROW 4
int sumArray(int arr[][COL])
{
  int sum = 0;
  for(int i=0; i < ROW ; i++)
    for(int j=0; j< COL; j++)
      if(i == 0 || j == 0 || i== ROW - 1 || j == COL-1)
          sum += arr[i][j];
  return sum;
}
void ArrayIn(int arr[][COL])
{
  for(int i=0; i < ROW ; i++)
    for(int j=0; j< COL; j++)
      cin >> arr[i][j];
}
int main()
{
    int arr[ROW][COL];
    cout << "Matrix_1: "<< endl;
    ArrayIn(arr);
    cout << "Summation is: " << sumArray(arr) << endl;
}
/*
1   2   3    4    5
14  15  16   17   6
13  1   9    18   7
12  11  10   9    8
*/
