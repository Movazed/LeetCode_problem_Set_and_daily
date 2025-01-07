#include<bits/stdc++.h>
#define pb push_back
#define vs vector<string> 
#define ss size_t
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vs result;
        long long n = words.size();
        for(long long i  = 0; i < n; i++){
            for(long long j = 0; j < n; j++){
                if(i != j && words[j].find(words[i]) != string::npos){
                    result.pb(words[i]);
                    break;
                }
            }
        }
        return result;
    }
};