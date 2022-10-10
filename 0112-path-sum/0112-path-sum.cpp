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
    bool hasPathSum(TreeNode* root, int tar, int sum = 0) {
        if (not root) return false;
        if (not root -> left and not root -> right) {
            return sum + root -> val == tar;
        }
        return hasPathSum(root -> left, tar, sum + root -> val) or 
            hasPathSum(root -> right, tar, sum + root -> val);
    }
};