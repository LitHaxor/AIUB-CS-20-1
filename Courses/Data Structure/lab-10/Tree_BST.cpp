#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;
    /*
          parent
        /       \
    left        right
    */
};
class BST {

  Node *root;
public:
  BST();

  // function declaration
  Node *getRoot();

  Node *Insert(Node *node,int key);

  Node * Search(Node *root, int key);

  void Insert(int key);

  void in_order(Node *node);

  void pre_order(Node *node);

  void post_order(Node *node);

  int FindMin(Node *node);

  int FindSuccesor(Node *node);

  Node *bst_delete(Node *node, int key);

  void bst_remove(int key);
};


int main()
{
  bool run=true;
  BST root;
  while(run)
  {
    cout << "**Binary Search Tree**" << endl;
    cout << "1. Insert " << endl;
    cout << "2. Treverse " <<endl;
    cout << "3. Search" << endl;
    cout << "4. Delete" <<endl;
    cout << "0. Exit"<<endl;
    cout << "Enter choice: "; int ch; cin >>ch;
    switch (ch) {
      case 1:
        int key;
        cout << "Enter value to push:";
        cin >> key;
        if(root.Search(root.getRoot(),key) == NULL)
          root.Insert(key);
        else
          cout << "Duplicate value found! Cannot insert\n";
        break;
      case 2:
        cout << "\t1. In-Order" << endl;
        cout << "\t2. Pre-order" << endl;
        cout << "\t3. Post-order" << endl;
        cout << "\tEnter choice:"; int ch2; cin >> ch2;
        switch (ch2) {
          case 1:
            root.in_order(root.getRoot());
            cout<<endl;
            break;
          case 2:
            root.pre_order(root.getRoot());
            cout << endl;
            break;
          case 3:
            root.post_order(root.getRoot());
            cout << endl;
            break;
        }
        break;
      case 3:
      cout << "Enter the element to search:" ;
      cin >> key;
      if(root.Search(root.getRoot(), key) == NULL)
        cout << "Element " << key << " not found!" << endl;
      else cout << "Element found at the tree!" << endl;
      break;
      case 4:
        cout << "Enter element to remove: ";
        cin >> key;
        root.bst_remove(key);
        break;
      case 5:
        cout << "Exiting program!" <<endl;
        return 0;
    }
  }
}


/*
 Implementing function body
*/
BST :: BST(){
  root = NULL; // constructor pointing to null
}

Node * BST :: getRoot(){
  return root; // return root
}

Node * BST :: Insert(Node *node,int key)
{
  if(node == NULL) // 1. if the root is null
  {
    node = new Node();
    node->data = key; //insert the key into data
    node -> left = NULL;
      /*
               data
            /      \
         null        null
      */

    node -> right = NULL;
    node-> parent=  NULL;
  }
  else if(node-> data < key) //2. if key value is bigger than node data
  {
    node -> right = Insert(node->right, key); // insert element at right
    /*
              25=root/parent
            /   \
    left= 20    40= right ,
                  \
                    60 key =60
    */
    node -> right -> parent = node;
  }
  else //3. ifthe key value is smaller than node data
    {
      /*
                25=root/parent
              /   \
      left= 20    40= right ,
          /
        10 = key
      */
      node ->left = Insert(node->left, key);
      node ->  left -> parent = node; //
    }
    return node;
}

Node * BST ::  Search(Node *root, int key)
{
  Node *node = root;
   if (node == NULL) // given key is not found
       return NULL;

   else if(node->data == key) // data is found
       return node;
   else if(node->data < key) // key is greater than current node's data
       return Search(node->right, key);
   else // key is smaller than current node's data
       return Search(node->left, key);
}

void BST ::  Insert(int key)
{
    root = Insert(root,key); // inserting into the root by calling Node * Insert fucntion
}

void BST ::  in_order(Node *node)
{
  if(node == NULL) // if node is empty exit
    return;
    // left - root -right
  in_order(node-> left);
  cout << node -> data << " ";
  in_order(node-> right);
}

void BST ::  pre_order(Node *node)
  {

    // print root left right
    cout << node -> data << " ";
    if(node == NULL)
      return;
    in_order(node-> left);

    in_order(node-> right);
  }

void BST ::  post_order(Node *node)
  {
    // left - right - root
    cout << node -> data << " ";
    if(node == NULL)
      return;
    in_order(node-> left);

    in_order(node-> right);
  }

Node* BST ::  bst_delete(Node *node, int key)
  {

  if(node  == NULL) return NULL; // 0. if the node is empty
  // Target node is found
  if (node->data == key)
  {
    // 1.if it is the leaf node
    if(node-> left == NULL && node -> right == NULL) // 1.1 if it a node is leaf node
      node = NULL; // node can be safely removed
    // 2. if the node has one child
    /*
              10
            /   \
          20     50
        /   \   /  \
      40    n  n   n
  1. deleting 40:
              10
            /   \
          20     50
        /   \   /  \
       n    n  n    n
    */
    else if( node -> left == NULL && node -> right != NULL)
    // 2.1 node has one child on the right
    /*
              11
            /   \
          12     20
        /   \   /  \
       n    30 n   n
  1. deleting 12:
                10
              /   \
            30     50
          /   \   /  \
         n    n  n    n
    */
      {
        node -> right -> parent = node -> parent;//connect the child node to the parent node directly
        node = node -> right; // transplant node
      }

    else if (node -> left != NULL && node -> right == NULL)
    // 2.2 node has a one child on the left
    /*
              11
            /   \
          12     20
        /   \   /  \
       7    n n   n
  1. deleting 12:
                10
              /   \
            7     50
          /   \   /  \
         n    n  n    n
    */

    {
      node -> left -> parent = node -> parent; // connect the child node to the parent's node
      node = node->left; // transplant
  }
    // 3. The node have two children (left and right)
    /*
              11
            /   \
          12     20
        /   \   /  \
       10    15 n   n
  1. deleting 12:
                10
              /   \
            15     50
          /   \   /  \
         10    n  n    n
    */
    else
    {
        int successorKey = FindSuccesor(node); // Find/search successor

        node->data = successorKey; // replace node data with successor data
        node->right = bst_delete(node->right, successorKey); // delete the old successor's key
    }
  }

  else if (node->data < key)  // if data is smaller then key , then search to the right
      node->right = bst_delete(node->right, key);

  else  // if data is greater then key , then search to the left
      node->left = bst_delete(node->left, key);


  return node;
}

void BST ::  bst_remove(int key)
  {
    root= bst_delete(root, key); // attaching new tree to the root
  }

int BST :: FindSuccesor(Node *node)
{

  if(node-> right != NULL) // successor is the minimum key of right
    return FindMin(node-> right);


   else  // If no any right subtree
   {
       Node * parentNode = node->parent;
       Node * currentNode = node;

        while ((parentNode != NULL) && (currentNode == parentNode->right)) // Treverse till root, current node -right
        {
            currentNode = parentNode; // Treverse currentNode
            parentNode = currentNode->parent;
        }

        return parentNode == NULL ?-1 :parentNode->data; // if parent node is not null then return data
  }
}

int BST :: FindMin(Node *node)
{
  if(node == NULL)
    return -1;
  else if(node -> left == NULL) // if left subtree is null then return data
    return node-> data;
  else
    return FindMin(node->left); // recurse till finding the max
}
