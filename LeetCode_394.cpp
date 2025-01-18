#include <bits/stdc++.h>
using namespace std;
#define ss stack<string>
class Solution {
public:
    string decodeString(string s) {
        ss st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ']'){
                string ans = "";
                while(st.top() != "["){
                    ans = st.top() + ans;
                    st.pop();
                }
                st.pop();
                string times = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    times = st.top() + times;
                    st.pop();
                }

                int to_times = stoi(times);
                string ret = "";
                while(to_times--){
                    ret = ans + ret;
                }
                st.push(ret);
            } else {
                st.push(string(1, s[i]));
            }
        }
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};