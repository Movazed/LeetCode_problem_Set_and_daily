#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// LeetCode 547 - Number of Provinces

class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[node] = 1;
        for(int i = 0; i < isConnected[node].size(); ++i){
            if(isConnected[node][i] == 1 && !vis[i]){
                dfs(i, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int provinces = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, isConnected, vis);
                provinces++;
            }
        }
        return provinces;
    }
};