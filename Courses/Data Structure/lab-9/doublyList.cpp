#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node *prev;
    Node *next;
};

void push_head (Node **head, int key) // takes the memory & address as head pointer
{
  Node *temp = new Node();

  temp-> data = key; // storing vlaue

  temp -> next = (*head); // head is now next of temp
  if( (*head) != NULL)
    (*head) -> prev = temp; // if head not null  store temp inot head
  (*head) = temp; // head points to temp
}
void push_mid (Node *prev_node, int key)
{
  if( prev_node == NULL) // if prev node null return
  {
    cout << "The previous node cannot be null!\n";
    return;
  }
  Node * temp = new Node(); // create new ptr
  temp -> data = key; // asing value
  temp -> next = prev_node -> next; // set temp [next] = prev[nex]
  prev_node -> next = temp; // set prev_node[next] = temp
  prev_node -> prev = prev_node; // set prev_node[prev]= previous_node itself
  if( temp -> next != NULL)
    temp -> next-> prev = temp; // points after new finding new null node
}

void push_last (Node ** head, int key)
{
  Node * temp = new Node();
  Node *treverse = *head;
  temp -> data = key;
  temp -> next = NULL;

  if( *head == NULL)
  {
    temp -> prev = NULL;
    *head = temp;
    return;
  }

  while (treverse -> next != NULL)
    treverse= treverse-> next;
  treverse->next = temp;
  temp -> prev = treverse;
}

void delete_node (Node *head, Node *node)
{
  if(node == head)
  {
    head = node -> next;
    head-> prev = NULL;
    delete node;
    return;
  }
  node->prev->next = node-> next;
  node->next -> prev = node -> prev;
  delete node;
  return;
}
void delete_head(Node *head)
{
  Node *node = head;
  head = node -> next;
  head-> prev = NULL;
  return;
}
void delete_mid(Node *head,Node *mid )
{
  delete_node(head, mid);
}
void delete_last(Node *head)
{
  Node *temp = head;
  while(temp != NULL)
    temp = temp -> next;
  delete_node(head, temp);
}

void Display(Node *node)
{
  Node *treverse = node;
  while(treverse != NULL)
  {
    cout << treverse -> data << " ";
      treverse= treverse -> next;
  }
  cout << endl;
}
int main()
{
  Node *head = NULL;

  cout << "10 has been pushed to head" <<endl;
  push_head(&head,10);
  Display(head);
  cout << "8 has been pushed to head"<< endl;
  push_head(&head, 8);
  Display(head);
  cout << "7 has been pushed/append to last"<< endl;
  push_last(&head,7);
    Display(head);
  cout << "12 has been inserted after head value 8.\n";
  push_mid(head-> next , 12);
    Display(head);
  cout << "\nHead(8) value has been deleted!" << endl;
  delete_head(head);
  Display(head);
  cout << "Head next value (12) has been deleted!" << endl;
  delete_mid(head, head);
  Display(head);

  cout << "last value has been deleted"<< endl;
  delete_last(head);
  Display(head);
}
