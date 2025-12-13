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
#define usll unsigned long long
#define qusll queue<pair<TreeNode*, unsigned long long>> 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        usll mw = 0;
        qusll q;
        q.push({root, 0});

        while (!q.empty()) {
            int sz = q.size();

            usll mmin = q.front().second;

            usll fr, ls;

            for (int i = 0; i < sz; i++) {
                usll cid = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) fr = cid;
                if (i == sz - 1) ls = cid;

                if (node->left) {
                    q.push({node->left, cid * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, cid * 2 + 2});
                }
            }

            mw = max(mw, ls - fr + 1);
        }
        return (int)mw;
    }
};