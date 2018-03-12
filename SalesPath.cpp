/* Find the root to leaf path with the least cost */


#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int cost;
  vector<Node *> children;
  Node *parent;
};

void dfs(Node*, int& , int);

int getCheapestCost( Node *rootNode )
{
  if(!rootNode) return 0;
  
  int minVal=INT_MAX;
  dfs(rootNode, minVal, 0);
  
  return minVal;
}

void dfs(Node* rootNode, int& minVal, int currVal) {
  if(!rootNode) return;
  
  currVal+=rootNode->cost;
  if(rootNode->children.empty()) {
    minVal = min(minVal, currVal);
  }
  
  for(auto& neighbor: rootNode->children) {
    dfs(neighbor, minVal, currVal);
  }
}

int main() {
  Node* root = new Node();
  root->cost=0;
  Node* child1 = new Node();
  child1->cost=5;
  Node* child2 = new Node();
  child2->cost=3;
  Node* child3 = new Node();
  child3->cost=2;
  Node* child4 = new Node();
  child4->cost=1;
  root->children.push_back(child1);
  child1->children.push_back(child3);
  root->children.push_back(child2);
  child2->children.push_back(child4);
  
  cout<<getCheapestCost(root);
  
  return 0;
}
