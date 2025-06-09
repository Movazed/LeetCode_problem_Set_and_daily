#include<bits/stdc++.h>
using namespace std;
// LeetCode 841 - Keys and Rooms

#include<bits/stdc++.h>
using namespace std;
// LeetCode 841 - Keys and Rooms

class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n = rooms.size();
            vector<bool> visited(n, false);      
            queue<int> q;
            q.push(0);
            visited[0] = true;
            int count = 1;

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for(int key : rooms[curr]){
                    if(!visited[key]){
                        visited[key] = true;
                        count++;
                        q.push(key);
                    }
                }
            }
            return count == n;

        }
    };