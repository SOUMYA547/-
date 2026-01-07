class Solution {
public:
    long long totalSum = 0;
    long long best = 0;
    const int MOD = 1e9 + 7;

    // subtree sum + product calculation
    long long dfs(TreeNode* root) {
        if (root == NULL) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long curr = left + right + root->val;

        best = max(best, curr * (totalSum - curr));

        return curr;
    }

    // total sum calculation
    long long getTotal(TreeNode* root) {
        if (root == NULL) return 0;
        return root->val + getTotal(root->left) + getTotal(root->right);
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotal(root);  // first DFS
        dfs(root);                  // second DFS
        return best % MOD;
    }
};
