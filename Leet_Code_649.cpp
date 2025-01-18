#include<bits/stdc++.h>
#define ll long long
#define cc const char
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        ll score = 0;

        for(ll i = 0; i < senate.size(); i++){
            cc ch = senate[i];

            if(ch == 'R'){
                if(score < 0){
                senate.push_back('D');
                }
                ++score;
            } else {
                if(score > 0){
                    senate.push_back('R');
                }
                --score;
            }
        }
        return (score > 0) ? "Radiant" : "Dire";
    }
};