#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int diameter = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {

        height(root);
        return diameter;
    }

    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};