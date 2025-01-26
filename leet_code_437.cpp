#include<bits/stdc++.h>
using namespace std;
#define ll long long


 // Definition for a binary tree node.
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
    ll cnt = 0;
    
    int solve(TreeNode* root, ll targetSum) {
        if (!root) {
            return 0;
        }
        
        ll count = 0;
        if (root->val == targetSum) {
            count++;
        }
        
        count += solve(root->left, targetSum - root->val);
        count += solve(root->right, targetSum - root->val);
        
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }
        
        cnt += solve(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        
        return cnt;
    }
};