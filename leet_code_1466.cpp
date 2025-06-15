#include<bits/stdc++.h>
using namespace std;
// LeetCode 1466. Reorder Routes to Make All Paths Lead to the City Zero

class Solution {
public:
    int dfs(vector<vector<int>> &al, vector<bool> &visited, int from){
        int change = 0;
        visited[from] = true;

        for(auto& to : al[from]){
            int next = abs(to);
            if(!visited[next]){
                change += dfs(al, visited, next) + (to > 0);
            }
        }
        return change;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> al(n);

        for(auto &c: connections){
            al[c[0]].push_back(c[1]);
            al[c[1]].push_back(-c[0]); // negative to indicate the direction of the road
        }
        vector<bool> visited(n, false);
        return dfs(al, visited, 0);
    }
};