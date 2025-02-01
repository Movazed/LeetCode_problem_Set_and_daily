#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        ll n = nums.size();
        for(ll i = 0; i < n - 1; i++){
           if( nums[i] % 2 == nums[i + 1] % 2){
            return false;
           }
        }
        return true;
    }
};