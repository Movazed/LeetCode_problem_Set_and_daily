#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        if(Head(root) == -1){
            return false;
        }
    }
    return true;

    int Height(TreeNode* root){
        if(root = NULL){
            return 0;
        }
        int heightLeft = Height(root->left);
        int heightRight = Height(root->right);

        if(heightLeft == -1 || heightRight == -1 || abs(heightLeft - heightRight) > 1){
            return -1;
        }

        return max(heightLeft, heightRight) + 1;
    }
};