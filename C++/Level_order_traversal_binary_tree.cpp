#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *left, *right;
};
node *newNode(int val)
{
    node *Node = new node();
    Node->val = val;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}
void print(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}
void levelOrderTraversal(node *root)
{
    vector<vector<int>> result;
    if (root == NULL)
    {
        print(result);
    }
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        vector<int> v;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            node *node = q.front();
            q.pop();

            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
            v.push_back(node->val);
        }
        result.push_back(v);
    }
    print(result);
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is-" << endl;
    levelOrderTraversal(root);

    return 0;
}