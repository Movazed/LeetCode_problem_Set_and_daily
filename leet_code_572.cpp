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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL){
            return true;
        }

        if(root == NULL){
            return false;
        }

        if(isIdentical(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode* a, TreeNode* b){
        if(a == NULL && b == NULL){
            return true;
        }
        if(a == NULL || b == NULL){
            return false;
        }
        if(a->val != b->val){
            return false;
        }

        return isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
    }
};