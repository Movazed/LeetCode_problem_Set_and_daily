#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define vi vector<int>
#define vll vector<ll>


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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vll ListNode_node1, ListNode_node2;

        getLeafValues(root1, ListNode_node1);
        getLeafValues(root2, ListNode_node2);

        return ListNode_node1 == ListNode_node2;
    }


    void getLeafValues(TreeNode* node, vll& ListNode){
        if(!node){
            return;
        }

        if(!node->left && !node->right){
            ListNode.pb(node->val);
            return;
        }

        getLeafValues(node->left, ListNode);
        getLeafValues(node->right, ListNode);
    }
};