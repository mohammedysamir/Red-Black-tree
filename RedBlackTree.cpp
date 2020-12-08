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
    if (Parent != NULL && Parent->parent != NULL)
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
      return NULL;
  }


bool isSameDirection(Node* current){
  Node *Parent=current->parent;
  Node *Uncle=getUncle(current);
  Node *GP=Parent->parent;
  //if (current is left of parent and uncle is left of GP) or (current is right of parent and uncle is right of GP) 
  if(GP!=NULL && Uncle !=NULL)
  {
    if((current==Parent->left && Uncle==GP->left)||(current==Parent->right && Uncle==GP->right))
       return true;
  }
  return false;
}

public:

bool isEmpty(){
  if(root==NULL)
    return true;
  else 
  return false;
}

void insert(int number)
  {
    //Check cases of Red-Black Tree
    Node *current_node = insertBT(number);
    //1. if current == root -----> turn root to black
    do{
    if (current_node == root)
    {
      root->Color = 1;
      break;
    }
    Node *Parent = current_node->parent;
    Node *GrandParent = Parent->parent;
    if (GrandParent != NULL)
    {
      Node *Uncle = getUncle(current_node);
      //2. if(current->parent.Color==1)----> just insert it  'Parent is black'
      if (Parent->Color == 1)
       break;
      //3. if(current->parent.Color==0 && current->uncle.Color==0) ---> switch color of p,u&Gp
      if (Parent->Color == 0)
      {
      if(Uncle !=NULL &&Uncle->Color == 0){
        Parent->Color = 1;
        Uncle->Color = 1;
        GrandParent->Color = 0;
        current_node=GrandParent;
      }
      if(Uncle==NULL ||(Uncle !=NULL && Uncle->Color==1)){
      //4. if(same direction)---> rotate to parent 
      if(isSameDirection(current_node))
      {
        int temp=Parent->value;
        Parent->value=current_node->value;
        current_node->value=temp;
        //cut pointer to parent 
        if(current_node==Parent->right){
          Parent->right=NULL;
        }else{
          Parent->left=NULL;
        }
        //re-insert currentNode to adjust positions
        current_node=insertBT(current_node->value);
      }
      //5. if(oppisite direction)---> rotate to parent's parent & switch color
      else{
        
      }
      }
    }
    }
    }while(current_node!=root && root->Color == 0);
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
