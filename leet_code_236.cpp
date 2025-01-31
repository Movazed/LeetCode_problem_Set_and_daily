#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == nullptr || root == p || root == q){
            return root;
        }       

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != nullptr && right != nullptr){
            return root;
        }

        return left != nullptr ? left : right;
    }
};

TreeNode* newNode(ll val){
    TreeNode* node = new TreeNode(val);
    return node;
}

int main() {

    TreeNode* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    TreeNode* p = root->left;
    TreeNode* q = root->left->right->right;
    Solution solution;
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    if (lca != nullptr) {
        cout << "The lowest common ancestor of nodes " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    return 0;
}