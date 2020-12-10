#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
// 1. pushing element into head
void push_head(Node **head, int new_data) // Pushing elements at beginning
{
  Node *temp  = new Node(); // creating dyn pointer
  temp-> data = new_data; // putting value to new node
  temp -> next = (*head); // pointing new node next to head
  (*head) = temp; // new_node inseted at the beginning
}

// 2. Pushing element into mid
void push_mid(Node *previous, int new_data) {
  if (previous->next == NULL) { // if given node hAS null memory
    cout << "Given prev_node cannot be NULL" <<endl;
    return;
  }
  Node * temp = new Node(); // new temp has been allocated
  temp-> data = new_data; // new data inserted to temp node
  temp -> next = previous-> next; // temp node is pointing to next node of prev node
  previous-> next = temp;  // prev node pointing to temp node  inserted
}

// pushing element into last
void push_last(Node **head, int new_data) {
  Node *temp = new Node(); // creating temp node
  Node *treverse = *head;
  temp -> data = new_data; // assinging new data
  temp -> next = NULL; // inserting at the last, so next ptr must be null

  if(*head == NULL)
  {
    *head = temp; // if head if empty temp will be new head
    return;
  }

  while (treverse->next !=  NULL)  // treversng till last elements pointing to NULL
  {
     treverse = treverse->next; // Changing traverse pointer 1 right
  }
  treverse-> next = temp; // assinging last node next ptr to new node pointer
  return;
}


// Treversing list and printing element
 void Display(Node *n) {
  if(n == NULL) return; // if node is null exit function
  Node *temp = n; // 1. make a temp node and assign head node into it
   while (temp != NULL) { // 2. treverse till node is null
     cout <<  temp-> data << " "; // 3. print data from dereferenced value
     temp = temp-> next; // 4. assign next pointer to current pointer
   }
    cout <<endl;
 }

 Node * Search(Node *head , int key)
 {
   if(head == NULL) return NULL; // if node is null nothing to search
   Node *treverse = head; // taking temp node
   while (treverse != NULL) { // treverse till node is null
     if(treverse-> data == key) // check the node matches the key value
        return treverse; // return the memory
      treverse = treverse-> next; // go one right
   }
   return NULL;

 }

void delete_key(Node **head, int key)
{
  Node *curr= *head; // store head to curr ptr
  Node *prev = NULL; //crete prev null ptr
  if( curr != NULL && curr-> data == key) // check if head value contains the value
    {
      *head = curr -> next; // head is changed to head next locaton
      delete curr; // free the memory
      return;
    }
  while(curr != NULL && curr -> data != key) // trevesing till curr is not empty and value is not mathced
  {
    prev = curr; // change the prev to curr to remove prev node
    curr= curr -> next; // curr node points to it's next loc
  }
  if(curr == NULL) return; // if data is not found delete

  prev-> next = curr->next; // point prev -> next node to curr next node
  delete curr;
}

void delete_last(Node *head)
{
  if(head == NULL) return; // if head null then nothing to del
  if(head -> next == NULL) return; // next to head node is null nothing to dleete
  Node *temp = head; // store head in temp ptr
  while(temp-> next -> next != NULL) // treverse till 2 right locaton of temp is not null
  {
    temp= temp -> next;// change temp pointer till last
  }
  delete (temp-> next); // delete last
  temp-> next = NULL; // and it points to nothing
  return;
}

int main() {
  bool val = true;
  Node *head =NULL;
  while (val) {
    cout << "\n** Singly Linked list **\n";
    cout << "1.Create a singly linked list\n";
    cout << "2.Display your list\n";
    cout << "3.Insert a new item\n";
    cout << "4.Search an item into your linked list.\n";
    cout << "5.Delete an item from the list\n";
    cout << "6.Exit\n";
    cout << "Enter chocice:";

    int ch; cin>> ch;
    switch (ch) {
      case 1:
        cout << "Creating Singly  Linked list!\n";
        int value;
        cout << "Enter element: "; cin >> value;
        push_head(&head, value);
        break;
      case 2:
        cout << "Displaying list\n";
        Display(head);
        break;
      case 3:
        cout << "\t1. Insert at the beginning\n";
        cout << "\t2. Insert at specefc locaton\n";
        cout << "\t3. Inset at last\n";
        cout << "Enter chocice:" ;
        int ch2; cin>> ch2;
        switch (ch2) {
          case 1:
            int value;
            cout << "Enter element: "; cin >> value;
            push_head(&head , value);
            break;
          case 2:
              int el;
              Display(head);
              cout << "Push element  after:";
              cin >> el;
              cout << "Enter element: "; cin >> value;
              push_mid(Search(head,el), value);
              break;
          case 3:
                cout << "Enter element: "; cin >> value;
                push_last(&head , value);
                break;
        }
        break;
      case 4:
        cout << "Enter element: ";
        cin >> value;
        cout <<"value: " << value << " was found at " << Search(head, value) << " address  \n";
        break;
      case 5:
        cout << "1. Delete element from head " << endl ;
        cout << "2. Delete element from middle " << endl;
        cout << "3. Delete element from last" <<endl;
        cout << "Enter choice: ";
        int ch3; cin >> ch3;
        switch (ch3) {
          case 1:
              if(head == NULL)
                break;
              head = head -> next;
              break;
          case 2:
          cout << "Node: ";
          Display(head);
          cout << "Enter value to delete: " << endl;

            int value;
            cin>>value;
          delete_key(&head, value);
          break;
          case 3:
            delete_last(head);
            break;
        }
        break;
      case 6:
        val = false;
        break;
      default:
        cout << "Wrong option!" << endl;
    }
  }
  return 0;
}
