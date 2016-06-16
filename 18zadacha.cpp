#include <iostream>
using namespace std;

int b=0;
int c[20];
int i = 0;

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
		void print(struct node* node);

		bool DFS(node *node);
		bool CheckForDuplicate(node *node, int value);

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

bool BinarySearchTree::DFS(node *node)
{
	bool hasDuplicate = false;
	if (node != NULL)
	{
		hasDuplicate = CheckForDuplicate(node->right, node->data);
		if (!hasDuplicate)
		{
			hasDuplicate = DFS(node->left);
			hasDuplicate = DFS(node->right);
		}
	}

	return hasDuplicate;
}

bool BinarySearchTree::CheckForDuplicate (node *node, int value)
{
	bool isFound = false;
	if (node != NULL)
	{
		if (value > node->data)
		{
			isFound = CheckForDuplicate(node->right, value);
		}
		else if (value < node->data)
		{
			isFound = CheckForDuplicate(node->left, value);
		}
		else
		{
			isFound = true;
		}
	}

	return isFound;
}




int main(){
	int a;
	cout << "make your choice \n 1:check for maches \n";
	cout << "your choice: ";
	cin >> a;
	BinarySearchTree *bst = new BinarySearchTree();
	while (a != 9){

		switch (a)
		{
		case 1:int k;
			cout << "insert number:";
			cin >> k;
			bst->insert(k);
			b++;
			break;
		case 2:
			if (bst->DFS(bst->root) == 1)
				cout << "there have mach\n";
			else
				cout << "no mach\n";break;
		default:
			break;
		}
		cout << "your choice: ";
		cin >> a;
	}
}







