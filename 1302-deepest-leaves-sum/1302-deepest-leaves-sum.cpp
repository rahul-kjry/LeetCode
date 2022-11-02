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
    map<int, vector<int>> mp;
    int maxLvl = 0;
    void treeTrav(TreeNode * rt, int lvl) {
        if (not rt) {
            return ;
        }
        mp[lvl].push_back(rt -> val);
        treeTrav(rt -> left, lvl + 1);
        treeTrav(rt -> right, lvl + 1);
        maxLvl = fmax(maxLvl, lvl);
    }
    int deepestLeavesSum(TreeNode* rt) {
        treeTrav(rt, 0);
        return accumulate(mp[maxLvl].begin(), mp[maxLvl].end(), 0);
    }
};