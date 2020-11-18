#include<iostream>
using namespace std;
#define EnQ queue.Enqueue
#define DeQ queue.Dequeue
#define PRINT queue.print()
class Queue {
  public:
  int *que; int rear, front, maxSize;

   Queue(int size)
  {
    maxSize = size;
    que = new int[size];
    rear=-1;
    front=-1;
  }
  void Enqueue(int element);
  void Dequeue();
  void print();
};

int main()
{
  Queue queue = Queue(6);
  EnQ(0); PRINT;
  EnQ(1); PRINT;
  EnQ(2); PRINT;
  DeQ(); PRINT;
  EnQ(3); PRINT;
  EnQ(4); PRINT;
  EnQ(5); PRINT;
  EnQ(6); PRINT;
  EnQ(7); PRINT;
  DeQ(); PRINT;
  DeQ(); PRINT;
  EnQ(8); PRINT;
}



void Queue :: Enqueue(int element)
{
  if (((front == 0) && (rear == -1)) || (rear == (front-1) % (maxSize-1))){
    cout << "Max size reached!" <<endl;
    return;
  }
  else if(front == -1){
    front = 0; rear = 0;
    que[rear] = element;
    cout << element << " Enqueued!";
  }
  else if ((rear == maxSize -1) && (front != 0)){
    rear = 0;
    que[rear] = element;
    cout << element << " Enqueued!";
  }
  else  {
    que[++rear] =element;
    cout << element << " Enqueued!";
  }

}
void Queue :: Dequeue()
{
  if (front == -1){
    cout << "Empty Queue!";
    return;
  }
  cout << que[front] << " Dequeued!";
  que[front] = -1;
  if(front == rear)
  {
    front = -1;
    rear = -1;
  }
  else if (front == maxSize -1)
    front =0;
  else
    front++;
}
void Queue :: print()
{
  if (front == -1) return;
  cout <<"\n\tQUEUE: ";
  if (rear >= front) {
    for (int i=front; i <= rear; i++)
      cout << que[i] << " " ;
    cout << endl<<endl;
  }
  else {
    for(int i=front ; i< maxSize; i++)
      cout << que[i] << " ";

    for(int i=0; i<=rear; i++)
      cout<< que[i] << " ";
    cout << endl<<endl;
  }

}
