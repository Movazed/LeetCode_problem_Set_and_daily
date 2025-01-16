#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        ll c1 = nums1.size();
        ll c2 = nums2.size();

        ll x1 = 0, x2 = 0;

        if(c1 % 2 != 0){
            for(ll num : nums2){
                x2 ^= num;
            }
        }

        if(c2 % 2 != 0){
            for(ll num : nums1){
                x1 ^= num;
            }
        }
        return x1 ^ x2;
    }
};