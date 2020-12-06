class Node{
public:
int value;
int Color; //color==0 "Red" , color==1 "black" , color==2 "Double-black"
Node*left;
Node*right;
Node*parent;
Node()
{
value=0;
Color=0;
left=nullptr;
right=nullptr;
parent=nullptr;
}


};