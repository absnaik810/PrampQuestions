#include <iostream>

using namespace std;

struct Node
{
  int key;
  Node *left;
  Node *right;
  Node *parent;
};

// Helper function that allocates a new Node 
Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use 
Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}

//https://stackoverflow.com/a/6335263/2172854

int findLargestSmallerKey(Node *rootNode, int num) 
{
  int val=-1;
  
  while(rootNode) {
    if(num<=rootNode->key)
      rootNode=rootNode->left;
    else {
      val=rootNode->key;
      rootNode=rootNode->right;
    }
  }
  
  return val;
}

int main() {
  Node* root = new Node();
  root->key=20;
  Node* child1 = new Node();
  child1->key=9;
  Node* child2 = new Node();
  child2->key=25;
  Node* child3 = new Node();
  child3->key=5;
  Node* child4 = new Node();
  child4->key=12;
  Node* child5 = new Node();
  child5->key=11;
  Node* child6 = new Node();
  child6->key=14;

  root->left=child1;
  root->right=child2;
  child1->left=child3;
  child1->right=child4;
  root->right=child2;
  child4->left=child5;
  child4->right=child6;
  
  cout<<findLargestSmallerKey(root, 13);
  
  return 0;
}
