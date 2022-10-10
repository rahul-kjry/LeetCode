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
    vector<vector<int>> res;
    
    void g(TreeNode * root, int tar, vector<int> vec) {
        if (not root) return ;
        vec.push_back(root -> val);
        tar -= root -> val;
        if (not root -> left and not root -> right and not tar) {
            res.push_back(vec);
        } 
        g(root -> left, tar, vec);
        g(root -> right, tar, vec);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        g(root, tar, vector<int>());
        return res;
    }
};