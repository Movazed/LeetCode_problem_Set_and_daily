#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            ll maxprefixsum = 0;
            ll minprefixsum = 0;
            ll prefixsum = 0;

            for(ll i = 0; i < nums.size(); i++){
                prefixsum += nums[i];

                minprefixsum = min(minprefixsum, prefixsum);
                maxprefixsum = max(maxprefixsum, prefixsum);
            }
            return maxprefixsum - minprefixsum;

        }
    };