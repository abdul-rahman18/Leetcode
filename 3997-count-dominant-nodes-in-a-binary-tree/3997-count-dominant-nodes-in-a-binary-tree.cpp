/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt;
    int postOrder(TreeNode* root)
    {
        if(root == nullptr) return INT_MIN;
        
        int l = postOrder(root->left);
        int r = postOrder(root->right);

        int mx = max(l,r);

        if(root->val >= mx) cnt++;

        return max(mx,root->val);
    }
    int countDominantNodes(TreeNode* root) {
        cnt = 0;
        
        postOrder(root);

        return cnt;
    }
};