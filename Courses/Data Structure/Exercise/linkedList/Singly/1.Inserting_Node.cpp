#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
};

void push(Node ** head, int new_data)
{
  Node * new_node = new Node(); // new node
  new_node -> data = new_data; // new data is pushed into new node
  new_node -> next  = (*head); // pointing next pointer to the curr head
  (*head) =  new_node;
}

void insert_After (Node * prev_node, int new_data)
{
  if(prev_node == NULL){
    cout << "Given prev_node cannot be NULL" <<endl;
    return;
  }
  Node * new_node = new Node();
  new_node-> data = new_data;
  new_node -> next = prev_node-> next;
  prev_node-> next = new_node;
}

void append(Node** head_ref, int new_data)
{

    // 1. allocate node
    Node* new_node = new Node();

    // Used in step 5
    Node *last = *head_ref;

    // 2. Put in the data
    new_node->data = new_data;

    // 3. This new node is going to be
    // the last node, so make next of
    // it as NULL
    new_node->next = NULL;

    // 4. If the Linked List is empty,
    // then make the new node as head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // 5. Else traverse till the last node
    while (last->next != NULL)
        last = last->next;

    // 6. Change the next of last node
    last->next = new_node;
    return;
}
void printList(Node *n)
{
  while(n != NULL)
  {
    cout << n-> data <<  " " <<endl;
    n = n->next;
  }
}

int main()
{
  Node * head = NULL;
  push(&head, 7);
  push(&head, 6);
  append(&head, 4);
  insert_After(head-> next, 9);
  printList(head);
}
