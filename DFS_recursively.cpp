#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data ;
	node* left;
	node* right;

};

class dfs_recurrsion
{
public:
	
	// pre_order traversal
	void pre_order(node* root) {

		if (root == NULL)return;
		
		// root
		cout << root->data << " ";
		// left
		pre_order(root->left);
		// right
		pre_order(root->right);

	}
	// post_order traversal
	void post_order(node* root) {

		if (root == NULL)return;
		
		// left
		pre_order(root->left);
		// right
		pre_order(root->right);
		// root
		cout << root->data << " ";

	}
	// in_order traversal
	void in_order(node* root) {

		if (root == NULL)return;
		
		// left
		in_order(root->left);
		// root
		cout << root->data << " ";
		// right
		in_order(root->right);
	}

};

int main()
{

	// tree


	//      2

	// 4	    6

	//  	 8	   10




	node* a = new (node);
	node* b = new (node);
	node* c = new (node);
	node* d = new (node);
	node* e = new (node);

	a->data = 2; a->left = b; a->right = c;
	b->data = 4; b->left = NULL; b->right = NULL;
	c->data = 6; c->left = d; c->right = e;
	d->data = 8; d->left = NULL; d->right = NULL;
	e->data = 10; e->left = NULL; e->right = NULL;

	node* root = a;

	dfs_recurrsion tr;

	cout << "pre_order::"; tr.pre_order(root); cout << endl;
	cout << "in_order::"; tr.in_order(root); cout << endl;
	cout << "post_order::"; tr.post_order(root); cout << endl;

	return 0;
}
