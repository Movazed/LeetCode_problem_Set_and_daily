#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
class Solution {
    public:
        int numberOfSubstrings(string s) {
            vll cnt(3, 0);
            ll left = 0;
            ll result = 0;

            for(ll i = 0; i < s.length(); i++){

                cnt[s[i] - 'a']++;

                while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0)
                {
                    /* code */
                    result += s.length() - i;
                    cnt[s[left] - 'a']--;
                    left++;
                }

            }
            return result;
        }
    };