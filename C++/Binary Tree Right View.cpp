vector <int> res;
	void dfs(TreeNode* root, int depth){
		if (res.size()==depth)
			res.push_back(root->val);
		else res[depth] = root->val;
		if (root->left) dfs(root->left,depth+1);
		if (root->right) dfs(root->right,depth+1);
	}
    vector <int> rightSideView(TreeNode* root) {
		if (!root) return res;
        dfs(root,0);
		return res;
    }
