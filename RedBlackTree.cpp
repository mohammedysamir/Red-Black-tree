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
    string Color=temp->Color?" (B) ":" (R) ";
    cout<<temp->value<<Color;
    inorder(temp->right);
  }
}
Node* RR(Node* current){
Node* Parent=current->parent;
Node* GP=Parent->parent;
//rotate
Parent->parent=GP->parent;
GP->parent->right=Parent;
GP->parent=Parent;
GP->right=Parent->left;
GP->right->parent=GP;
Parent->left=GP;
return Parent;
}
Node* LL(Node* current){
  Node*Parent=current->parent;
  Node*GP=Parent->parent;
  Parent->parent=GP->parent;
GP->parent->left=Parent;
GP->parent=Parent;
GP->left=Parent->right;
GP->left->parent=GP;
Parent->right=GP;
  return Parent;
}

Node* LR(Node* current){
  Node* Parent=current->parent;
  Node* GP=Parent->parent;
  Parent->right=current->left;
  Parent->right->parent=Parent;

  //rotate child over parent

  current->left=Parent;
  Parent->parent=current;

  //rotate child over GP
  current=LL(Parent);
  return current;
}

Node* RL(Node* current){
  Node* Parent=current->parent;
  Node* GP=Parent->parent;
  Parent->left=current->right;
  Parent->left->parent=Parent;

  //rotate child over parent

  current->right=Parent;
  Parent->parent=current;

  //rotate child over GP
  current=RR(Parent);
  return current;
}
Node *getUncle(Node *current)
  {
    Node *Parent = current->parent;
    if (Parent != NULL && Parent->parent != NULL)
    {
      Node *GP = Parent->parent;
      if (GP != NULL)
      {
        if (Parent == GP->left)
        {
          return GP->right;
        }
        else
        {
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
  if(GP!=NULL)
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
      current_node->Color = 1;
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
      else if(Uncle==NULL ||(Uncle !=NULL && Uncle->Color==1)){
       //4. if(same direction)---> rotate to parent 
      if(isSameDirection(current_node))
      {
        if(current_node==Parent->right){
          Parent=LR(current_node);
          Parent->right->Color=0; //change old GP's color

        }
        else{
          Parent=RL(current_node);
          Parent->left->Color=0;

        }
         GrandParent=Parent->parent;
         //switch parent and GP colors
         Parent->Color=1;
         break;//terminate case
      }
      //5. if(oppisite direction)---> rotate to parent's parent & switch color
      else{
        if(current_node==Parent->left){
          //left-left rotation
          Parent=LL(current_node);
          Parent->right->Color=0; //change old GP's color
        }
        else{
          //right-right rotation
          Parent=RR(current_node);
          Parent->left->Color=0;
        }
         GrandParent=Parent->parent;
         //switch parent and GP colors
         Parent->Color=1;
         break;//terminate case
      }
      }
    }
    }
    }while( current_node == root && root->Color ==0 );
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
