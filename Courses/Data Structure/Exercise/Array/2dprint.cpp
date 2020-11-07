#include<iostream>
using namespace std;
//function for accessing
#define COL 3 //defining column
#define ROW 3 // defining row
void printArray(int arr[][COL], int col, int row)
{
    for(int i=0; i < ROW; i++){
        for(int j=0; j < COL; j++)
            cout << arr[i][j] << " " ; // 0th row all colums will be printed first
        cout << endl;
    }
}

int main()
{
  int arr[ROW][COL] = {{1,2,3},
                 {4,5,6},
                 {7,8,9}};
    printArray(arr, COL, ROW);
}
  /*
   * This program uses
   *
   */
