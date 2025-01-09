#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ld ans = 0;
        ld sum = 0;

        for(ll i = 0; i < k; i++){
            sum += nums[i];
        }

        ans = sum;

        for(ll i = k; i < nums.size(); i++){
            sum += nums[i];
            sum -= nums[i-k];
            ans = max(ans, sum);
        }
        return ans / k;
    }
};