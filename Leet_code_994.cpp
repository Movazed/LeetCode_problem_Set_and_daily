#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> ans = grid;
        int n = grid.size();
        int m = grid[0].size();

        int time = -1;

        int delRow = {-1, 0, +1, 0};
        int delCol = {0, +1, 0, -1};
    }
};