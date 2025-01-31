
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
    ll max_length = 0;

    void solve(TreeNode* root, ll dir, ll curr_length){
        if(!root){
            return;
        };

        max_length = max(max_length, curr_length);
        
        solve(root->left, 0, dir ? curr_length + 1 : 1);
        solve(root->right, 1, dir ? 1 : curr_length + 1);
        }

    int longestZigZag(TreeNode* root) {
        solve(root, 0, 0);
        solve(root, 1, 0);

        return max_length;
    }
};

int32_t main() {
        // Example usage:
    // Constructing a binary tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    //       / \
    //      7   8


    //DRY RUN

    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    Solution sol;

    ll result = sol.longestZigZag(root);
    cout << result << endl;

    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}