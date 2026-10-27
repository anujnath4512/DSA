
class Solution {
public:
    int dfs(TreeNode* root, int maxSoFar) {
        if (root == nullptr) {
            return 0;
        }

        int good = 0;

        if (root->val >= maxSoFar) {
            good = 1;
        }

        maxSoFar = max(maxSoFar, root->val);

        good += dfs(root->left, maxSoFar);
        good += dfs(root->right, maxSoFar);

        return good;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
