#include<iostream>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node (int val)
  {
    data = val;
    left= NULL;
    right= NULL;
  }
};

void pre_order(Node *node)
{
  cout << node-> data << " " << endl;
  if(node -> left != NULL)
  {
    pre_order(node->left);
  }
  if(node -> right != NULL)
  {
    pre_order(node->right);
  }
}
void post_order(Node *node)
{
  if(node -> left != NULL)
  {
    post_order(node->left);
  }
  if(node-> right != NULL){
    post_order(node-> right);
  }
  cout << node-> data<< " ";
}
int main()
{
  Node *root = new Node(1);
      /*
         1
      /    \
    Null   Null
      */
  root -> left = new Node(2);
  /*
       1
     /  \
   2    Null
  */
  root -> right = new Node(3);
  /*
         1
      /    \
    2       3
  */
  root -> left -> left = new Node(4);

  pre_order (root);
}
