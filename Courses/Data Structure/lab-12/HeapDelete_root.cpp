#include<iostream>
using namespace std;

class HeapTree {
  int *heap= NULL; int size;
public:

  // class function
    HeapTree(int size);

    void Heapify(int size, int i);

    void Create_heap(int size);

    void Build_heap();

    void inputArray();

    void printArray();

    void remove_root();
};

// main function
int main()
{
  cout << "\t\t\t**Binary Heap Tree**" << endl;
  cout << "\t\t\t-Implentation of deletation from the root-" << endl;
  int size;
  cout << "Enter size: ";
  cin >> size;
  cout << "Enter heap: ";
  HeapTree heapTree = HeapTree(size);
  heapTree.inputArray();
  heapTree.Build_heap();
  cout << "Current heap: ";
  heapTree.printArray();
  heapTree.remove_root();
  cout << "After Deleting the root inside heap:\n";
  heapTree.printArray();
}


/** implementing heap function**/
HeapTree :: HeapTree(int size)
{
  this -> size = size;
  Create_heap(size);
}

/***  Removing root function ***/
void HeapTree :: remove_root()
{
  /*
   * Removing node from the root
   * so root will be heap[0]
  */
  for(int i=0; i < size -1  ; i++) // deleting from the root and reducing size -1
    heap[0] = heap[i+1]; // element shifts one space ahead

  --size; // decrease the size of heap
  Create_heap(size); // dynamically create the new heap of new size
  Build_heap(); // rebuild the new heap
}

void HeapTree :: Create_heap(int size)
{
  if(heap == NULL) {
    heap = new int[size];
    return;
  }
  cout << "New size: " << size << endl;
  int *temp = new int[size];
  for(int i=0; i < size; i++)
    temp[i] = heap[i];
  delete [] heap;
  this -> size = size;
  heap = temp;
  delete [] temp;
}

void HeapTree :: Heapify(int size , int i)
{
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int max = i;

  if( left < size && heap[max] < heap[left] )
    max = left;
  if(right < size && heap[max] < heap[right])
    max = right;
  if( i != max)
  {
    swap(heap[i], heap[max]);
    Heapify(size,max);
  }
}
void HeapTree :: Build_heap()
{
  for(int i= (size/2) -1; i >= 0; i--)
    Heapify(size, i);
}



void HeapTree :: inputArray()
{
  for( int i=0 ; i < size; i++)
    cin >> heap[i] ;
}
void HeapTree :: printArray()
{
  for(int i =0; i < size ; i++)
    cout << heap[i] << " ";
  cout << endl;
}
