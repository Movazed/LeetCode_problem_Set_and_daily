#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, vector<pair<string, double>>> adjList;
    unordered_map<string, bool> visited;
    double queryAns;
    
public:

    bool dfs(string startNode, string endNode, double runningProduct){
        if(adjList.find(startNode) == adjList.end() || adjList.find(endNode) == adjList.end()){
            return false;
        }

        if(startNode == endNode and adjList.find(startNode) != adjList.end()){
            queryAns = runningProduct;
            return true;
        }
        bool tempAns = false;
        visited[startNode] = true;

        for(int i = 0; i < adjList[startNode].size(); i++){
            if(!visited[adjList[startNode][i].first]){
                tempAns = dfs(adjList[startNode][i].first, endNode, runningProduct*adjList[startNode][i].second);
                if(tempAns){
                    break;
                }
            }
        }
        visited[startNode] = false;
        return tempAns;
    }   

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        int m = queries.size();
        vector<double> ans(m);


        // Build the adjacency list from equations and values
        for(int i = 0; i < n; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adjList[u].push_back({v, val});
            adjList[v].push_back({u, 1.0/val});
        }

        for(int i = 0; i < m; i++){
            queryAns = 1;
            visited.clear();
            bool pathFound = dfs(queries[i][0], queries[i][1], 1);
            if(pathFound){
                ans[i] = queryAns;
            } else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};