#include<iostream>
using namespace std;

void rotate_Array(int arr[], int n, int d)
{
    int temp[d];
    for(int i=0; i< d; i++)
        temp[i] = arr[i];
    for(int i=n; i>d; i--)
        arr[i-d] = arr[i-1];
    for(int i=0; i< d; i++)
        arr[n-i] = temp[i];
}


int main()
 {
	int t, n, d;
	cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> d;
        int arr[n];
        for(int i=0; i<n;i++)
            cin >> arr[i];

        rotate_Array(arr, n, d);

        for(int i=0;i<n-1;i++)
            cout<< arr[i] << " ";
    }
    return 0;
 }
