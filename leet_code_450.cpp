#include<bits/stdc++.h>
using namespace std;

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
        int getMax(TreeNode* root){
            if(!root){
                return -1;
            }

            while (root->left)
            {
                root = root->left;
            }
            return root->val;            
        }

        TreeNode* deleteNode(TreeNode* root, int key) {
            if(!root){
                return NULL;
            }

            if(root->val == key){
                if(!root->left && !root->right){
                    delete root;
                    return NULL;
                }

                else if(!root->left && !root->right){
                    TreeNode* rightNode = root->right;
                    root->right = nullptr;
                    delete root;
                    return rightNode;
                }
                else if(root->left && !root->right){
                    TreeNode* leftNode = root->left;
                    root->left = nullptr;
                    delete root;
                    return leftNode;
                }
                else if(root->left && root->right){
                    int minValue = getMax(root->left);
                    root->val = minValue;

                    root->left = deleteNode(root->left, minValue);
                    return root;
                }
            }

            else if(root->val < key){
                root->right = deleteNode(root->right, key);
            }
            else {
                root->left = deleteNode(root->left, key);
            }
            return root;
        }
    };