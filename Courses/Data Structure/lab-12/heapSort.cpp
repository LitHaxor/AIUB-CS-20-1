#include<iostream>
using namespace std;

class HeapTree {
    int *heap = NULL; int size;
  public:
    // fucntion declare
    HeapTree(int s);

    void heapify( int size, int i);

    void heapSort();

    void printArray();

    void inputArray();
};


// main function
int main()
{
  cout <<"\t\t\t** Binary Heap Tree**" << endl;
  cout << "\t\t\t-Implentation of heapSort-" << endl;
  int size;
  cout << "Enter size: ";
  cin >> size;
  HeapTree heapTree = HeapTree(size);
  cout << "Enter heap: ";
  heapTree.inputArray();
  cout << "Sorted array is:" << endl;
  heapTree.heapSort();
  heapTree.printArray();
}


/* implementing class function */
HeapTree :: HeapTree(int size)
{
  heap = new int[size]; // creates heap of size 'size'
  this -> size = size;
}


void HeapTree :: printArray()
{
  for(int i=0; i < size ; ++i)
    cout << heap[i] << " " ;
  cout << endl;
}

void HeapTree :: heapSort()
{
  for(int i = (size/2)- 1; i >= 0 ; i-- ) // building heap from non-leaf last node to root
    heapify( size, i);


  for(int i= size - 1; i > 0; i--) // extract one by one index
    {
      swap(heap[0], heap[i]); // move current root to the end node

      heapify( i, 0); //  store max item into root/heapify node index i
    }
}

void HeapTree :: heapify( int size, int i)
{
  int max = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  // if left node is larger than root node
  if( left < size && heap[left] > heap[max])
    max = left;

  // if right node is larger than root node
  if( right < size && heap[right] > heap[max])
    max = right;

  // if index is not the root index
  if(max != i)
  {
    swap(heap[i], heap[max]); // swap current with index

    heapify( size , max); // heapify recursively for each node leaf
  }
}
void HeapTree :: inputArray()
{
  for(int i =0; i < size ; i++)
    cin >> heap[i] ;
}
