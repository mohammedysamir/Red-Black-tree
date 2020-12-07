#include<iostream>
#include"Node.cpp"
using namespace std;
/*
1.insert 
2.delete
3.print   Done
4.clear   Done
*/
class RedBlackTree{
private:
Node* root=NULL;
//regular insert of binary search
Node* insertBT(int number){
  Node *newnode=new Node();
  newnode->value=number;
  if(isEmpty())
  //insert node as a note
    {
      root=newnode;
    }
  else{
  Node* temp=root;
  Node* parent;
  while(temp!=nullptr)    //traversal
  {
    parent=temp;
    if(number>temp->value){
    temp=temp->right;
    }
    else{
    temp=temp->left;
    }
  }
  if(number>parent->value)
    parent->right=newnode;
  else 
    parent->left=newnode;
  newnode->parent=parent;
  }
  return newnode;
}

void inorder(Node* temp){
  if(temp==nullptr)
    return;
  else{
    inorder(temp->left);
    cout<<temp->value<<" ";
    inorder(temp->right);
  }
}

Node *getUncle(Node *current)
  {
    Node *Parent = current->parent;
    if (Parent == NULL || Parent->parent == NULL)
      return NULL; //root node
    else
    {
      Node *GP = Parent->parent;
      if (Parent->parent != root)
      {
        if (Parent == GP->left)
        {
          //uncle is right child
          return GP->right;
        }
        else
        {
          //uncle is left child
          return GP->left;
        }
      }
    }
  }

public:

bool isEmpty(){
  if(root==NULL)
    return true;
  else 
  return false;
}

void insert(int number){
  //Check cases of Red-Black Tree
  Node* current_node=insertBT(number);

//1. if current == root -----> turn root to black 
  if(current_node==root)
  {
    root->Color=1;
    return;
  }
  Node* Parent=current_node->parent;
  Node* Uncle=getUncle(current_node);
  Node* GrandParent=Parent->parent;
  //2. if(current->parent.Color==1)----> just insert it  'Parent is black'
  if(Parent->Color==1) return;
  //3. if(current->parent.Color==0 && current->uncle.Color==0) ---> switch color of p,u&Gp
  if(Parent->Color==0 && Uncle->Color==0){
  Parent->Color=1;
  Uncle->Color=1;
  GrandParent->Color=0;
  }
//4. if(same direction)---> rotate to parent
//5. if(oppisite direction)---> rotate to parent's parent & switch color
}

void Print(){
  if(root!=NULL)
    {
      inorder(root);
    cout<<endl;
    }
    else{
    cout<<"Empty Tree"<<endl;
    }
}

void Clear(){
  root->value=0;
  root->right=NULL;
  root->left=NULL;
  root=NULL;
}

};
