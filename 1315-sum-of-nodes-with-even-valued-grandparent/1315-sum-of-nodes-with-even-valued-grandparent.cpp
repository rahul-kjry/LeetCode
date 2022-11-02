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
    #define L left
    #define R right
    #define V val
    int sumEvenGrandparent(TreeNode* root, int sum = 0) {
        if (not root) {
            return sum;
        }
        if (root -> val % 2 == 0) {
            if (root -> L) {
                if (root -> L -> L) {
                    sum += root -> L -> L -> V;
                }
                if (root -> L -> R) {
                    sum += root -> L -> R -> V;
                }
                
            }  
            if (root -> R) {
                if (root -> R -> L) {
                    sum += root -> R -> L -> V;
                }
                if (root -> R -> R) {
                    sum += root -> R -> R -> V;
                }
            }
        }
        return sum + sumEvenGrandparent(root -> L) + sumEvenGrandparent(root -> R);
    }
};