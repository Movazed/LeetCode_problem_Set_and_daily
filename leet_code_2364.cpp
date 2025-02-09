#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define umll unordered_map<ll, ll>


class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            umll freq;
            ll good_pairs = 0;
            ll n = nums.size();

            for(ll i = 0; i < n; i++){
                ll key = nums[i] - i;
                good_pairs += freq[key];
                freq[key]++;
            }

            return (n * (n - 1)) / 2 - good_pairs;
        }
    };