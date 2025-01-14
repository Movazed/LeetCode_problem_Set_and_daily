#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ll left = 0;
        ll max_length = 0;
        ll zero_count = 0;
        

        for(ll right = 0; right < nums.size(); right++){
            if(nums[right] == 0){
                zero_count++;
            }

            while(zero_count > 1){
                if(nums[left] == 0){
                    zero_count--;
                }
                left++;
            }

            max_length = max(max_length, right - left);
        }
        return max_length;
    }
};