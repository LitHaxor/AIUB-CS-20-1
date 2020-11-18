#include<iostream>
using namespace std;

class Queue {
  int *que;
  int maxSize, rear , front;
  int counter;
public:
    Queue(int size)
    {
      maxSize = size;
      rear = -1;
      front = -1;
      counter= 0;
      que = new int[maxSize];
    }
    void resize(int x){
      maxSize = x;
      int *temp;
      temp = que;
      que = new int [maxSize];
      que = temp;
    }


  void enque(int element)
  {

    if (((front == 0) && (rear == -1)) || (rear == (front-1) % (maxSize-1))){
      resize(maxSize+1);
    }
      else if(front == -1){
        front = 0; rear = 0;
        que[rear] = element;
        cout << "C" << ++counter << "=" << element <<endl;

      }
      else if ((rear == maxSize -1) && (front != 0)){
        rear = 0;
        que[rear] = element;
      cout << "C" << ++counter << "=" << element <<endl;
      }
      else  {
        que[++rear] =element;
        cout << "C" << ++counter << "=" << element <<endl;
      }
  }
  void dequeue()
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

  int calculate()
  {
    int sum = 0;
    if (front == -1) return -1;
    if (rear >= front) {
      for (int i=front; i <= rear; i++)
        sum += que[i];
    }
    else {
      for(int i=front ; i< maxSize; i++)
        sum += que[i];

      for(int i=0; i<=rear; i++)
        sum += que[i];
    }
    return sum;
  }
};

int main()
{

  cout << "For inline queue:"<<endl ;
  Queue q = Queue(5);
  q.enque(500);
  q.enque(600);
  q.enque(450);
  q.enque(1000);
  q.enque(1500);
  cout << "Cash in inline Queue:" << q.calculate()<<endl;
  cout << "For outline queue:" <<endl;
  Queue q2 = Queue(5);
  q2.enque(1550);
  q2.enque(2000);
  q2.enque(300);
  q2.enque(150);
  q2.enque(350);
  q2.enque(3000);
  cout << "Cash in waiting queue: " << q2.calculate() <<endl;
}
