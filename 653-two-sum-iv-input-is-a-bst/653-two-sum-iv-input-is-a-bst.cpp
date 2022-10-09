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
    vector<int> nums;
    
    void treeTrav(TreeNode * root) {
        if (not root) return ;
        treeTrav(root -> left);
        nums.push_back(root -> val);
        treeTrav(root -> right);
    }
    bool findTarget(TreeNode* root, int tar) {
        treeTrav(root);
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum == tar) return true;
            else if (sum < tar) ++ lo;
            else -- hi;
        }
        return false;
    }
};