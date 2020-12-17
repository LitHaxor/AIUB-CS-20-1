#include<iostream>
using namespace std;

class HeapTree {
  int *heap= NULL; int size;
public:
    // function declaration
    HeapTree(int size);

    void Heapify(int size, int i);

    void Create_heap(int size);

    void Build_heap();

    void inputArray();

    void printArray();

    void Insert(int element);
};

// main fucntion
int main()
{
  cout << "\t\t\t**Binary Heap Tree**" << endl;
  cout <<"\t\t\t-Implenting Insertion in Heap" << endl;
  int size;
  cout << "Enter size: ";
  cin >> size;
  cout << "Enter heap: ";
  HeapTree heapTree = HeapTree(size);
  heapTree.inputArray();
  heapTree.Build_heap();
  cout << "Current heap: ";
  heapTree.printArray();
  cout << "Enter new element: "; int element;
  cin >> element;
  heapTree.Insert(element);
  cout << "After Inserting "  << element << " inside heap:\n";
  heapTree.printArray();
}


/* Heap function */
HeapTree :: HeapTree(int size)
{
  this -> size = size;
  Create_heap(size);
}

/**  Insertion function   **/
void HeapTree :: Insert(int element)
{
  ++size; // increase size of heap
  Create_heap(size); // dynamically adjust the size of heap
  heap[size - 1] = element; // at the last of heap insert the heap
  Build_heap(); // rearrange/ rebuild the heap
}

void HeapTree :: Create_heap(int size) // create heap dynamically alloacted new heap
{
  if(heap == NULL) { // if heap is null then create new heap
    heap = new int[size];
    return;
  }
  cout << "New size: " << size << endl;
  int *temp = new int[size];// create temp heap
  for(int i=0; i < size; i++) //copy all element into heap
    temp[i] = heap[i];
  delete [] heap; // delete the heap
  this -> size = size;
  heap = temp; // point temporary heap to new heap
  delete [] temp; // delete the heap
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
