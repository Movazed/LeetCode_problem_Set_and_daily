#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            ll n = nums.size();
            ll inz = 0;

             for(ll i = 0; i < n - 1; i++){
                if(nums[i] == nums[i + 1]){
                    nums[i] *= 2;
                    nums[i + 1]  = 0;
                }
             }

             for(ll i = 0; i < n; i++){
                if(nums[i] != 0){
                    nums[inz++] = nums[i];
                }
             }

             while (inz < n)
             {
                    nums[inz++] = 0;
             }
             
             return nums;
        }
    };