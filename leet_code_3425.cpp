#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = edges.size() + 1;

        // <to, length>
        vector<vector<array<int, 2>>> adj(n);
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        // prefix sum of edges lengths
        vector<int> pre;
        map<int, int> res;
        map<int, vector<int>> occurence;

        // length = 0 -> min 1 node
        res[0] = 1;
        auto dfs = [&](this auto&& dfs, int v, int parent,
                int startDepth, int currDepth) -> void {
            int val = nums[v];
            if(!occurence[val].empty()) {
                startDepth = max(startDepth, occurence[val].back() + 1);
            }
            occurence[val].push_back(currDepth);

            int nodes = currDepth - startDepth + 1;
            int edges = nodes - 1;
            if(edges > 0) {
                int sz = pre.size();
                int len = pre[sz-1];
                if((sz-edges-1) >= 0) len -= pre[sz-edges-1];
                if(res.count(len)) {
                    res[len] = min(res[len], nodes);
                }else {
                    res[len] = nodes;
                }
            }


            for(auto& [nextV, edgeLen] : adj[v]) {
                if(nextV != parent) {
                    if(pre.empty()) pre.push_back(edgeLen);
                    else pre.push_back(pre.back() + edgeLen);
                    dfs(nextV, v, startDepth, currDepth + 1);
                    pre.pop_back();
                }
            }


            occurence[val].pop_back();
        };
        dfs(0, -1, 0, 0);
        return {res.rbegin()->first, res.rbegin()->second};
    }
};