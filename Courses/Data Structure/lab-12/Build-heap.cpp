#include<iostream>
using namespace std;


class MaxHeap{
  int heap_size;
  int * heap = NULL;
public:
    // function declare
    MaxHeap(int size);

    void swap(int *left, int *right);

    void Heapify(int index);

    void Build_heap();

    void printHeap();

    void getHeap();


};

// main fucntion
int main()
{
  cout << "\t\t\t**Heap**" << endl;
  cout << "\t\t\t-Building Heap-" << endl;
  cout << "Enter heap size: " ;
  int heap_size;
  cin >> heap_size;
  MaxHeap heap = MaxHeap(heap_size);
  cout << "Enter heap elements:"; heap.getHeap();
  heap.Build_heap();
  cout << "Max Heap: ";
  heap.printHeap();
}


/* fucntion body */
MaxHeap :: MaxHeap(int size) // 1. Constructor to initialize array
{
  heap = new int[size];  // array initialize of size
  heap_size = size;
}

void MaxHeap :: Heapify(int index) // converts normal array to heap
{
  /*
                            Max Heap
         parent                0                   0
        /      \            /     \              /  \
      left    right       2*0+1   2*0 +2        1    2
  */
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  int max = index; // initialize Current index as max root

  if( left <= heap_size && heap[left] > heap[max] ) // if left child is larger than the parent/root
    max = left; // left is current highest
  if( right <= heap_size && heap[right] > heap[max] )  // if right child is larger than the parent/root
    max = right; // right is current highest
  if( index != max) // if max index is not root index
  {
    swap(&heap[max], &heap[index]); // swap current max element with index element
    Heapify(max); // recurse through all sub tree
  }
}

void MaxHeap ::  Build_heap()
{
  // index starts from last leaf node to root
  for(int i= (heap_size/2) -1 ; i>= 0 ; i--) // reverse treverse from non-leaf node to root
    Heapify(i); // heapify node-leaf each node
}

void  MaxHeap :: swap(int *left, int *right)
{
  int temp = *left;
  *left = *right;
  *right = temp;
}

void MaxHeap :: printHeap()
{
  for(int i=0; i < heap_size ; i++)
    cout << heap[i] <<  " " ;
  cout << endl;
}
void MaxHeap :: getHeap()
{
  for(int i=0; i < heap_size ; i++)
    cin >> heap[i];
}
