#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node structure
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr; // Tree is empty or node not found

        if (root->val > key) {
            // Search in the left subtree
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            // Search in the right subtree
            root->right = deleteNode(root->right, key);
        } else {
            // Found the node to delete
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root; // Free memory
                return temp; // Replace with right child
            }
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root; // Free memory
                return temp; // Replace with left child
            }

            // Node has two children:
            // Get inorder successor (smallest in right subtree)
            TreeNode* temp = root->right;
            while (temp->left) {
                temp = temp->left;
            }

            // Copy inorder successor's value
            root->val = temp->val;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};

// Helper function to insert nodes (to build initial tree)
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Helper function for in-order traversal (to verify BST)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    // Building a sample BST
    vector<int> values = {50, 30, 70, 20, 40, 60, 80};
    TreeNode* root = nullptr;
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Initial BST (In-order): ";
    inorder(root);
    cout << "\n";

    Solution sol;

    int key = 70; // Node to delete
    cout << "Deleting node with value " << key << "\n";

    root = sol.deleteNode(root, key);

    cout << "BST after deletion (In-order): ";
    inorder(root);
    cout << "\n";

    return 0;
}