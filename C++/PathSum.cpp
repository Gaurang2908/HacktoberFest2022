
#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
	int val;
	TreeNode *left, *right;
};

// Function that returns a new TreeNode
// with given value
struct TreeNode* addNode(int data)
{
	// Allocate memory
	struct TreeNode* node
		= (struct TreeNode*)malloc(
			sizeof(struct TreeNode));

	// Assign data to val variable
	node->val = data;
	node->left = NULL;
	node->right = NULL;
	return node;
};

// Function that calculates the root to
// leaf path sum of the BT using DFS
void dfs(TreeNode* root, int sum,
		vector<int>& pathSum)
{
	// Return if the node is NULL
	if (root == NULL)
		return;

	// Add value of the node to
	// the path sum
	sum += root->val;

	// Store the path sum if node is leaf
	if (root->left == NULL
		and root->right == NULL) {

		pathSum.push_back(sum);
		return;
	}

	// Move to the left child
	dfs(root->left, sum, pathSum);

	// Move to the right child
	dfs(root->right, sum, pathSum);
}

// Function that finds the root to leaf
// path sum of the given binary tree
void findPathSum(TreeNode* root)
{
	// To store all the path sum
	vector<int> pathSum;

	// Calling dfs function
	dfs(root, 0, pathSum);

	// Printing all the path sum
	for (int num : pathSum) {
		cout << num << " ";
	}
	cout << endl;
}

// Driver Code
int main()
{
	// Given binary tree
	TreeNode* root = addNode(30);
	root->left = addNode(10);
	root->right = addNode(50);
	root->left->left = addNode(3);
	root->left->right = addNode(16);
	root->right->left = addNode(40);
	root->right->right = addNode(60);

	/* The above code constructs this tree

				30
			/	 \
		10	 50
		/ \	 / \
		3 16 40 60
*/

	// Function Call
	findPathSum(root);

	return 0;
}
