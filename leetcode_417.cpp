//DFS SOLUTION!!!! EASIER CALCULAYTED ACCORDING TO THE DEPTH FIRST SEARCH   2021/10/12                                                      
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));

        for(int i = 0; i < m; i++){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n-1);
        }

        for(int j = 0; j < n; j++){
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j){
        int m = h.size();
        int n = h[0].size();

        vis[i][j] = true;

        if(i - 1 >= 0 && vis[i-1][j] != true && h[i-1][j] >= h[i][j]){
            dfs(h, vis, i - 1, j);
        }

        if(i + 1 < m && vis[i+1][j] != true && h[i+1][j] >= h[i][j]){
            dfs(h, vis, i + 1, j);
        }

        if(j - 1 >= 0 && vis[i][j-1] != true && h[i][j-1] >= h[i][j]){
            dfs(h, vis, i, j - 1);
        }

        if(j + 1 < n && vis[i][j+1] != true && h[i][j+1] >= h[i][j]){
            dfs(h, vis, i, j + 1);                                                                  
        }
    }
};