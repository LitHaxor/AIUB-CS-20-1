#include<iostream>
using namespace std;
class Stack {
  int *stack,top, max;
public:
  Stack(int size);
  ~Stack();
  void reSize(int size);
  void push();
  void pop();
  void show();
  int getMax();
  int getTop();
};

int main()
{
  bool running = true;
  Stack st = Stack(1);
  while(running)
  {
    cout << "|| Dynamic Stack ||" <<endl;
    cout << "|| Size:" <<st.getMax() <<" TOP:" << st.getTop()  << " ||" <<endl;
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
int Stack :: getTop() {return top;}
int Stack :: getMax() {return max;}
Stack :: ~Stack(){
  cout << "Killing memory!";
  delete [] stack;
}
void Stack ::  push()
{
  if(top == max ) {reSize(max+1);}
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
void Stack :: reSize(int Size)
{

  int *temp = new int[max + Size];
  for(int i=0; i < max;i++) temp[i] = stack[i];
  max = Size;
  delete [] stack;
  stack = temp;
}
