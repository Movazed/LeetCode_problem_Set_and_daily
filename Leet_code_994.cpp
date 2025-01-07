//4 DIRECTIONSS!!!!! BFS  - 0ms

class Solution {
public:
    void move(vector<vector<bool>>& visit, vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& q, int& fresh){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visit[x][y] || grid[x][y] == 0){
            return;
        }

        if(grid[x][y] == 1){
            visit[x][y] = true;
            q.push({x, y});
            fresh--;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));

        queue<pair<int, int>> q;

        int fresh = 0;
        int minute = 0;

        for(int i  = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    visit[i][j] = true;
                } else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){

                auto [x, y] = q.front();
                q.pop();

                move(visit, grid, x + 1, y, q, fresh);
                move(visit, grid, x - 1, y, q, fresh);
                move(visit, grid, x, y + 1, q, fresh);
                move(visit, grid, x, y - 1, q, fresh);
            }
            if(!q.empty()){
            minute++;
            }
        }
        return fresh == 0 ? minute : - 1;
    }
};