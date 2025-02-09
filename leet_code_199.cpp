#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define qtn queue<TreeNode*>
#define pb push_back
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
        vector<int> rightSideView(TreeNode* root) {
            vi level;
            qtn q;
            if(!root){
                return level;
            }

            q.push(root);

            while (!q.empty())
            {
                ll n = q.size();

                for (ll i = 0; i < n; i++)
                {
                    TreeNode* node = q.front();
                    q.pop();

                    if(i == n - 1){
                        level.pb(node->val);
                    }

                    if(node->left){
                        q.push(node->left);
                    }

                    if(node -> right){
                        q.push(node->right);
                    }
                }   
            }
            return level;
        }
    };