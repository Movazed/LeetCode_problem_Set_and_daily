#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            vector<int> b;
    
            for(int i = 0, j = 0, count = 0, x, y; ; ++count){
                if(i < nums.size() && (j >= b.size() || nums[i] <= b[j])){
                    x = nums[i++];
                }
                else {
                    x = b[j++];
                }
                if(x >= k){
                    return count;
                }
                if(i < nums.size() && (j >= b.size() || nums[i] <= b[j])) {
                    y = nums[i++];
                }
                else {
                    y = b[j++];
                }
                long t = 2L * x + y;
                b.push_back(t < k ? (int) t : k);
            }
            return -1;
        }
    };