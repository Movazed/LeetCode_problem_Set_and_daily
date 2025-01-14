#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        ll ma = 0;
        ll ca = 0;

        for(ll i = 0; i < gain.size(); i++){
            ca += gain[i];

            ma = max(ma, ca); 
        }
        return ma;
    }
};