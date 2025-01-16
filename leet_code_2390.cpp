#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef string str;
#define pb pop_back
class Solution {
public:
    string removeStars(string s) {
        str c = "";

        for(ll i = 0; i < s.size(); i++){

            if(s[i] == '*'){
                c.pb();
            }
            else {
               c += s[i];
            }
        }
        return c;
    }
};