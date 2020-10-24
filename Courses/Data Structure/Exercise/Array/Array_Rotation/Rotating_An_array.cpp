#include<iostream>
using namespace std;
void reverse(int arr[], int start, int end)
{
  while(start< end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++; end--;
  }
}

void leftRotate(int arr[], int n, int d)
{
  if (d == 0)
    return;
  d = d % n;
  reverse(arr,0, d-1); // a[0-d] ; ar[n-d]
  reverse(arr,d, n-1);
  reverse(arr, 0, n-1);
}
void print(int arr[], int n)
{
  for(int i=0; i< n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
int main()
{
  int t, n, d;
  cin >> t;
  while(t--){
    cin >> n >> d;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>> arr[i];
    leftRotate(arr, n, d);
    print(arr,n);
  }
}
