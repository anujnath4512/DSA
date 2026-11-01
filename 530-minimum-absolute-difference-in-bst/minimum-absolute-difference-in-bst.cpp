
class Solution {
public:

    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, ans);

        ans.push_back(root->val);

        inorder(root->right, ans);
    }

    int getMinimumDifference(TreeNode* root) {

        vector<int> ans;

        inorder(root, ans);

        int mini = INT_MAX;

        for (int i = 1; i < ans.size(); i++) {
            int diff = ans[i] - ans[i - 1];

            mini = min(mini, diff);
        }

        return mini;
    }
};
