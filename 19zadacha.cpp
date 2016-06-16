#include <iostream>
using namespace std;
int sum = 0;

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
		int printEven(struct node*);

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
int BinarySearchTree::printEven(struct node* node){

	if (node == NULL) return 0;
	printEven(node->left);
	if ((node->data) % 2 == 0)
		sum = sum + node->data;
	printEven(node->right);
	return sum;
}



int main(){
	int a;
	cout << "make your choice \n 1: for insert \n 2: print sum of even numburs\n ";
	cout << "your choice: ";
	cin >> a;
	BinarySearchTree *bst = new BinarySearchTree();
	while (a != 9){
		int result = 0;

		switch (a)
		{
		case 1:int i;
			cout << "insert number:";
			cin >> i;
			bst->insert(i);
			break;
		case 2:  result = bst->printEven(bst->root);
			cout << result<<"\n";
				break;
		default:
			break;
		}
		cout << "your choice: ";
		cin >> a;
	}
}







