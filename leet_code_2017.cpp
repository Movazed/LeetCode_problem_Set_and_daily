#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll top = 0;
        for(int i = 0; i < grid[0].size(); i++){
            top += grid[0][i];
        }

        ll bottom = 0; ll res = LLONG_MAX;

        for(int i = 0; i < grid[0].size(); i++){
            top -= grid[0][i];
            res = min(res, max(top, bottom));
            bottom += grid[1][i];           
        }
        return res;
    }
};