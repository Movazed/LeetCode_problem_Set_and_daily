#include<bits/stdc++.h>
using namespace std;
#define us unordered_set<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define ll long long
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        us set_1;
        us set_2;

        vi ans_1;
        vi ans_2;

        for(ll i = 0; i < nums1.size(); i++){
            set_1.insert(nums1[i]);
        }

        for(ll j = 0; j < nums2.size(); j++){
            set_2.insert(nums2[j]);
        }

        for(auto one : set_1){
            if(set_2.find(one) == set_2.end()){
                ans_1.push_back(one);
            }
        }

        for(auto two : set_2){
            if(set_1.find(two) == set_1.end()){
                ans_2.push_back(two);
            }
        }

        vvi ans;

        ans.pb(ans_1);
        ans.pb(ans_2);

        return ans;
    }
};