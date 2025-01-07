#include<bits/stdc++.h>
#define vi vector<int>
#define leftside (node->left)
#define rightside (node->right)
#define LOOP(i , s) for(ll i = 0; i < (s); ++i)
typedef long long ll;
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


class Solution {
public:
    vi rightSideView(TreeNode* root) {
        fast_io;
        vi result;
        if(root == NULL){
            return result;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            ll s = q.size();
            vi v;

            LOOP(i,s){
                TreeNode* node = q.front();
                q.pop();
                if(i == s - 1){
                    result.push_back(node->val);
                }
                if leftside{
                    q.push(node->left);
                }
                if rightside{
                    q.push(node->right);
                }
            }

        }
        return result;
    }
};