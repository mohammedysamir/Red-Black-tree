#include <iostream>
#include "Node.cpp"
using namespace std;
/*
1.insert  Done
2.delete
3.print   Done
4.clear   Done
*/
class RedBlackTree
{
private:
	Node* root = NULL;
	//regular insert of binary search
	Node* insertBT(int number)
	{
		Node* newnode = new Node();
		newnode->value = number;
		if (isEmpty())
			//insert node as a note
		{
			root = newnode;
		}
		else
		{
			Node* temp = root;
			Node* parent = root;
			while (temp != nullptr) //traversal
			{
				parent = temp;
				if (number > temp->value)
				{
					temp = temp->right;
				}
				else
				{
					temp = temp->left;
				}
			}
			if (number > parent->value)
				parent->right = newnode;
			else
				parent->left = newnode;
			newnode->parent = parent;
		}
		return newnode;
	}

	void inorder(Node* temp)
	{
		if (temp == nullptr)
			return;
		else
		{
			inorder(temp->left);
			string Color ;
			if(temp->Color == 0)Color="(R)";
			else if (temp->Color==1)Color="(B)";
			else Color ="(DB)";
			cout << temp->value << Color;
			inorder(temp->right);
		}
	}
	Node* RR(Node* current)
	{
		Node* Parent = current->parent;
		Node* GP = Parent->parent;
		//rotate
		Parent->parent = GP->parent;
		if (GP->parent != NULL && isRight(GP))
			GP->parent->right = Parent;
		else if (GP->parent != NULL && !isRight(GP))
			GP->parent->left = Parent;
		else if (GP->parent == NULL) //parent becomes root
			root = Parent;
		GP->parent = Parent;
		GP->right = NULL;
		if (Parent->left != NULL)
		{
			GP->right = Parent->left;
			GP->right->parent = GP;
		}

		Parent->left = GP;
		return Parent;
	}
	Node* LL(Node* current)
	{
		Node* Parent = current->parent;
		Node* GP = Parent->parent;
		Parent->parent = GP->parent;
		if(GP->parent != NULL && isRight(GP))
			GP->parent->right = Parent;
		else if(GP->parent != NULL && !isRight(GP))
			GP->parent->left = Parent;
		else if (GP->parent == NULL) //parent becomes root
			root = Parent;
		GP->parent = Parent;
		GP->left = NULL;
		if (Parent->right != NULL)
		{
			GP->left = Parent->right;
			GP->left->parent = GP;
		}
		Parent->right = GP;
		return Parent;
	}

	Node* LR(Node* current)
	{
		Node* Parent = current->parent;
		Node* GP = Parent->parent;
		Parent->right = NULL;
		if (current->left != NULL)
		{
			Parent->right = current->left;
			Parent->right->parent = Parent;
		}

		//rotate child over parent

		current->left = Parent;
		current->parent = GP;
		Parent->parent = current;

		//rotate child over GP
		current = LL(Parent);
		return current;
	}

	Node* RL(Node* current)
	{
		Node* Parent = current->parent;
		Node* GP = Parent->parent;
		Parent->left = NULL;
		if (current->right != NULL)
		{
			Parent->left = current->right;
			Parent->left->parent = Parent;
		}

		//rotate child over parent

		current->right = Parent;
		current->parent = GP;
		Parent->parent = current;

		//rotate child over GP
		current = RR(Parent);
		return current;
	}
	Node* getUncle(Node* current)
	{
		Node* Parent = current->parent;
		if (Parent != NULL && Parent->parent != NULL)
		{
			Node* GP = Parent->parent;
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

	bool isSameDirection(Node* current)
	{
		Node* Parent = current->parent;
		Node* Uncle = getUncle(current);
		Node* GP = Parent->parent;
		//if (current is left of parent and uncle is left of GP) or (current is right of parent and uncle is right of GP)
		if (GP != NULL)
		{
			if ((current == Parent->left && Uncle == GP->left) || (current == Parent->right && Uncle == GP->right))
				return true;
		}
		return false;
	}

	//perform deletion of BST
	Node* deleteBT(int number) {
		Node* temp = root;
		while (temp->value != number) {
			if (temp->value < number)temp = temp->right;
			else temp = temp->left;
		}
		//1. delete leaf
		if (temp->left == NULL && temp->right == NULL)
		{
			return temp;
		}
		//2. delete Node has 1 child
		else if (temp->right == NULL && temp->left != NULL) {
			temp->value = temp->left->value;
			return temp->left;
		}
		else if (temp->left == NULL && temp->right != NULL) {
			temp->value = temp->right->value;
			return temp->right;
		}
		//3. delete Node has 2[Subtrees,Childred]
		return getPredecessor(temp);
	}

	Node* getPredecessor(Node* current) {
		Node* temp = root;
		//traverse to reach current
		while (temp->value != current->value) {
			if (temp->value < current->value)
			{
				temp = temp->right;
			}
			else temp = temp->left;
		}

		if (temp->left == NULL)
		{
			return temp;
		}
		//getting Predecessor
		temp = temp->left;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		return temp;
	}

	Node* getSibling(Node* current)
	{
		Node* parent = current->parent;
		if (current == parent->left)
		{
			return parent->right;
		}
		return parent->left;
	}

	bool isRight(Node* current) {
		Node* Parent = current->parent;
		if (current == Parent->right)return true;
		return false;
	}

public:
	bool isEmpty()
	{
		if (root == NULL)
			return true;
		else
			return false;
	}

	void insert(int number)
	{
		//Check cases of Red-Black Tree
		Node* current_node = insertBT(number);
		//1. if current == root -----> turn root to black
		do
		{
			if (current_node == root)
			{
				current_node->Color = 1;
				break;
			}
			Node* Parent = current_node->parent;
			Node* GrandParent = Parent->parent;
			if (GrandParent != NULL)
			{
				Node* Uncle = getUncle(current_node);
				//2. if(current->parent.Color==1)----> just insert it  'Parent is black'
				if (Parent->Color == 1)
					break;
				//3. if(current->parent.Color==0 && current->uncle.Color==0) ---> switch color of p,u&Gp
				if (Parent->Color == 0)
				{
					if (Uncle != NULL && Uncle->Color == 0)
					{
						Parent->Color = 1;
						Uncle->Color = 1;
						GrandParent->Color = 0;
						current_node = GrandParent;
					}
					else if (Uncle == NULL || (Uncle != NULL && Uncle->Color == 1))
					{
						//4. if(same direction)---> rotate to parent
						if (isSameDirection(current_node))
						{
							if (current_node == Parent->right)
							{
								Parent = LR(current_node);
								Parent->right->Color = 0; //change old GP's color
							}
							else
							{
								Parent = RL(current_node);
								Parent->left->Color = 0;
							}
							GrandParent = Parent->parent;
							//switch parent and GP colors
							Parent->Color = 1;
							break; //terminate case
						}
						//5. if(oppisite direction)---> rotate to parent's parent & switch color
						else
						{
							if (current_node == Parent->left)
							{
								//left-left rotation
								Parent = LL(current_node);
								Parent->right->Color = 0; //change old GP's color
							}
							else
							{
								//right-right rotation
								Parent = RR(current_node);
								Parent->left->Color = 0;
							}
							GrandParent = Parent->parent;
							//switch parent and GP colors
							Parent->Color = 1;
							break; //terminate case
						}
					}
				}
			}
		} while (current_node == root && root->Color == 0);
	}

	void Delete(int number) {
		Node* temp = deleteBT(number);
		Node* parent = temp->parent;
		//1-temp->color=0 delete 
		if (temp->Color == 0)
		{
			cout << "Red Node" << endl;
			if (isRight(temp))
			{
				parent->right = NULL;
			}
			else
				parent->left = NULL;
			temp->parent = NULL;
			return;//terminating case
		}
		//2-temp->color=1 (double black problem)
		else if (temp->Color == 1) {
			//Change temp->color to 2 'double black'
			temp->Color = 2;
			cout << "Black Node" << endl;
			// case 1:d=double black is root ----> make it black and delete
			if (temp == root)
			{
				root->Color = 1;
				root = NULL;
				return; //terminating case
			}
			do {
				Node* Sibling = getSibling(temp);
				Node* RightNephew = Sibling->right;
				Node* LeftNephew = Sibling->left;
				// case 2 p=black s =red n=black{rotate and switch s,p}

				if (parent->Color == 1 && Sibling->Color == 0 && RightNephew->Color == 1 && LeftNephew->Color == 1)
				{
					cout << "Case 2 " << endl;
					if (Sibling == parent->right)
					{
						RR(RightNephew);
					}
					else
					{
						LL(LeftNephew);
					}
					Sibling->Color = 1;
					parent->Color = 0;
					break;
				}
				// cas 3 p=black s=black n=black{d=black....p=D....s=red}
				// cas 4 p=red s=black n=black{D=black ....switch color s,p}
				// case5  s=black n=red{n,D same direction 1:rotate n on s...2:switch colorn,s}
				// case6  s=black n=red{n,doubleblack opposite direction...1:rotate parent n on gp namespace 2:switch color:n,p,gp....3:D=black}
			} while (temp != NULL);
		}
	}

	void Print()
	{
		if (root != NULL)
		{
			inorder(root);
			cout << endl;
		}
		else
		{
			cout << "Empty Tree" << endl;
		}
	}

	void Clear()
	{
		root->value = 0;
		root->right = NULL;
		root->left = NULL;
		root = NULL;
	}
};
