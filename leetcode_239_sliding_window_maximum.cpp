#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;

        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        for(int i = k; i < nums.size(); i++){
            if(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

