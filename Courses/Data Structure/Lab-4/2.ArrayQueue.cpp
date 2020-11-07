#include<iostream>
using namespace std;

class Queue {
  public:
  int *queue, rear, front, maxSize;

  Queue(int size);
  void Enqueue();
  void Dequeue();
  void show();
};

int main()
{
  bool running = true; int size;
  cout << "Enter Size:";
  cin >> size;
  Queue que= Queue(size);
  while(running)
  {
    cout << "What you want to do?" <<endl;
    cout << "1. Enqueue element in the Queue."<<endl;
    cout << "2. Dequeue element in the queue." <<endl;
    cout << "3. Display the Queue." <<endl;
    cout << "4. DIE" <<endl;
    int choice;
    cout << "\nEnter your choice:";
    cin >> choice;
    switch (choice) {
      case 1:
        que.Enqueue();
        break;
      case 2:
        que.Dequeue();
        break;
      case 3:
        que.show();
        break;
      case 4:
        running = false;
        break;
      default:
        cout << "Invalid options provided!" <<endl;
    }
  }
}


Queue :: Queue(int size)
{
  maxSize = size;
  queue = new int[size];
  rear=0;
  front=0;
}
void Queue :: Enqueue()
{
  if(front == 0 && rear == maxSize) {cout << "\n\nQueue size max\n"<<endl; return;}
  int element;
  cout << "Enter element:";
  cin >> element;
  rear =rear+1 % maxSize;
  queue[rear] = element;
}
void Queue :: Dequeue()
{
  if(front == -1) {cout << "\n\nQueue size empty\n"<<endl; return;}
  front = front +1 % maxSize;
}
void Queue :: show()
{
  if( front == -1) {cout << "\n\nQueue size empty\n"<<endl; return;}
  int i= front+1;
  cout<< "Showing items:" <<endl<<endl;
  while(i <= rear)
  {
    cout << queue[i]  << " ";
    i++;
  }
  cout <<endl<<endl;
}
