#include <iostream>
using namespace std;


class BinarySearchTree{
	struct node
	{
		int data;
		node *left;
		node *right;
	};
public:
	node* root;

public: BinarySearchTree()
{
			root = NULL;
}

		bool isEmpty() { return root == NULL; }
		void insert(int);
		void printPositive(struct node*);
		void printNegative(struct node*);
};

void BinarySearchTree::insert(int d){
	node *t = new node;
	node*parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;

	if (isEmpty()) root = t;
	else{

		node* curr;
		curr = root;

		while (curr){
			parent = curr;
			if (t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}
		if (t->data < parent->data)
			parent->left = t;
		else parent->right = t;
	}
}
void BinarySearchTree::printPositive(struct node* node){
	if (node == NULL) return;
	printPositive(node->left);
	if (node->data>0)
		cout << node->data << "\n";
	printPositive(node->right);
}
void BinarySearchTree::printNegative(struct node* node){
	if (node == NULL) return;
	printNegative(node->left);
	if (node->data <= 0)
		cout << node->data << "\n";
	printNegative(node->right);
}



int main(){
	int a;
	cout << "make your choice \n 1: for insert \n 2: for positive\n 3:for negative\n 9:for EXIT!! \n";
	cout << "your choice: ";
	cin >> a;
	BinarySearchTree *bst = new BinarySearchTree();
	while (a != 9){

		switch (a)
		{
		case 1:int i;
			cout << "insert number:";
			cin >> i;
			bst->insert(i);
			break;
		case 2: bst->printPositive(bst->root); break;
		case 3: bst->printNegative(bst->root); break;
		default:
			break;
		}
		cout << "your choice: ";
		cin >> a;
	}
}







