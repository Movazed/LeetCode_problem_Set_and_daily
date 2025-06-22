#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        int fresh = 0;
        int time = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int rot = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int r = curr[0];
            int c = curr[1];
            int t = curr[2];

            time = max(time, t);

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    q.push({nr, nc, t + 1});
                    rot++;
                }
            }
        }
        return rot == fresh ? time : -1;
    }
};


