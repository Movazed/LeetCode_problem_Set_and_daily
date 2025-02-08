#include<bits/stdc++.h>
using namespace std;
#define ll long long
//Definition for a binary tree node.
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
        int maxLevelSum(TreeNode* root) {
            if (root == NULL) {
                return 0;
            }
    
            queue<TreeNode*> q;
            q.push(root);
    
            long long max_sum = LLONG_MIN;
            int level = 1;
            int result_lvl = 1;
    
            while (!q.empty()) {
                int size = q.size();
                long long lvl_sum = 0;
    
                for (int i = 0; i < size; i++) {
                    TreeNode* curr = q.front();
                    q.pop();
    
                    lvl_sum += curr->val;
    
                    if (curr->left != NULL) {
                        q.push(curr->left);
                    }
    
                    if (curr->right != NULL) {
                        q.push(curr->right);
                    }
                }
    
                  if(lvl_sum > max_sum){
                    max_sum = lvl_sum;
                    result_lvl = level;
                  }
                  level++;
            }
            return level;
        }
    };