#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        ll oddCount = 0, prefixSum = 0;
        for(ll a : arr){
            prefixSum += a;
            oddCount += prefixSum % 2;
        }
        oddCount += (arr.size() - oddCount) * oddCount;
        return oddCount % 1'000'000'007;
    }
};