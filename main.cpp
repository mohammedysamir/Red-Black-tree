#include <iostream>
#include"RedBlackTree.cpp"
int main() {
	RedBlackTree* rb = new RedBlackTree();
	string reply="Yes";
	cout << "Red-Black Tree" << endl;
	do {
		cout << "enter number to do operation" << endl;
		cout << "1. Insert value(s)" << endl;
		cout << "2. Delete value(s)" << endl;
		cout << "3. Print Tree" << endl;
		cout << "4. Clear Tree" << endl;
		int choice; cin >> choice;
		switch (choice)
		{
			int num_values;
			int value;
		case 1:
			
			cout << "How many values you want to add" << endl;
			cin >> num_values;
			while (num_values--) {
				cout << "enter value to add" << endl;
				cin >> value;
				rb->insert(value);
			}
			break;
		case 2:
			cout << "How many values you want to delete" << endl;
			cin >> num_values;
			while (num_values--) {
				cout << "enter value to add" << endl;
				cin >> value;
				rb->Delete(value);
			}
			break;
		case 3:
			rb->Print();
			break;
		case 4:
			rb->Clear();
			break;
		default:
			cout << "invalid choice" << endl;
			break;
		}
		cout << "want to do extra operation(s) on this tree? enter 'No' , 'no' or 'n' to exit " << endl;
		cin >> reply;
	} while (!(reply == "No" || reply == "no" || reply == "n"));

}











/*
Tested Values :
	13 , 8 , 1 , 11 , 6 ,17 ,15 ,25 ,22 ,27 
*/