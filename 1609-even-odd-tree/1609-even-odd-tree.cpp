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
    bool isEvenOddTree(TreeNode* root) {
        int lvl = 0;
        queue<TreeNode *> que;
        que.push(root);
        while (not que.empty()) {
            vector<int> vec;
            for (int i = que.size(); i > 0; --i) {
                TreeNode * frnt = que.front(); que.pop();
                if (frnt -> left) {
                    que.push(frnt -> left);
                }
                if (frnt -> right) {
                    que.push(frnt -> right);
                }
                if (lvl & 1 and not vec.empty()) {
                    if (vec.back() <= frnt -> val) {
                        return false;
                    }
                }
                if (lvl & 1 ^ 1 and not vec.empty()) {
                    if (vec.back() >= frnt -> val) {
                        return false;
                    }
                }
                if (lvl & 1 and frnt -> val & 1) {
                    return false;
                }
                if (lvl & 1 ^ 1 and frnt -> val & 1 ^ 1) {
                    return false;
                }
                
                vec.push_back(frnt -> val);
            }
                // cout << lvl << " - ";
                // for (int i : vec) cout << i << " ";
                // cout << endl;
            ++ lvl;
        }
        return true;
    }
};