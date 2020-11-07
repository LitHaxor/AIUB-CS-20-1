#include<iostream>
using namespace std;
class Stack {
  int *stack,top, max;
public:
  Stack(int size);
  ~Stack();
  void push();
  void pop();
  void show();
  int getTop();
};

int main()
{
  bool running = true; int size;
  cout << "Enter size of the stack:";
  cin >> size;
  Stack st = Stack(size);
  while(running)
  {
    cout << "|| Static Stack ||" <<endl;
    cout << "|| Size:" <<size <<" TOP:" << st.getTop()  << " ||" <<endl;
    cout << "-------------------" <<endl;
    cout << "What you want to do?"<<endl;
    cout << "1. Push element in the stack." << endl;
    cout << "2. Pop element in the stack." << endl;
    cout << "3. Display the stack." << endl;
    cout << "4. DIE" << endl;
    cout << "Enter your choice:";
    int choice;
    cin >> choice;
    switch (choice) {
      case 1:
        st.push();
        break;
     case 2:
        st.pop();
        break;
      case 3:
        cout << "\n\nShowing stack:" <<endl;
        st.show();
        break;
      case 4:
        running = false;
        break;
      default:
        cout << "Wrong choice!";
    }
  }
}




Stack :: Stack(int size)
{
  max = size;
  stack = new int[max];
  top =0;
}
Stack :: ~Stack(){
  cout << "Killing memory!";
  delete [] stack;
}

int Stack :: getTop()
{
  return top;
}
void Stack ::  push()
{
  if(top == max ) {cout << "\nStack is full!\n\n" ; return;}
  int element;
  cout << "Enter value to push in the stack:";
  cin >> element;
  stack[top++] = element;
}
void Stack :: pop ()
{
  if(top == 0) {cout << "Stack is empty!"; return;}
  stack[top] = 0;
  top--;
}
void Stack :: show()
{
  if(top == 0) {cout << "empty stack"; return;}
  int i = top -1;
  while(i > -1){
    cout << stack[i] << endl;
    i--;
    }
    cout << endl<<endl;
}
