#include<iostream>
using namespace std;

#define TOP stk.Top()
#define PUSH stk.push
#define EMPTY stk.empty()
#define POP stk.Pop
#define PRINT stk.print()

class Stack {
  int  top ; int max ; char *arr;
public:
  Stack(int max)
  {
    this -> max = max;
    arr = new char[max];
    top = -1;

  }

  char Top();

  bool Empty();

  bool isMax();

  void push(char element);

  void Pop();

  void print();
};


int main()
{
  Stack stk = Stack(6) ;

  PUSH('a'); PRINT;

  PUSH('b'); PRINT;

  PUSH('c'); PRINT;

  POP(); PRINT;

  PUSH('d'); PRINT;

  POP(); PRINT;

  PUSH('e'); PRINT;

  POP(); PRINT;

  POP(); PRINT;

  POP(); PRINT;

  return 0;
}



bool Stack :: isMax ()
{
  return (top == max);
}
bool Stack :: Empty()
{
  return (top == 0);
}
char Stack :: Top() {
  return arr[top];
}
void Stack :: Pop() {
  if(top == 0) return;
  cout << Top() << " is poped! " <<endl;
  top--;
}
void Stack :: push(char element)
{
  if(isMax()) return;
  cout << element << " is pushed! " << endl;
  top++;
  arr[top] = element;
}


void Stack :: print()
{
  cout << "\n\tStack: ";
  for(int i=0; i <= top; i++)
    cout <<  arr[i]  << " ";
  cout << endl << endl;
}
