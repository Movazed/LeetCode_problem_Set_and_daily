#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = int;

#define fr(i,a,b) for(ii i=(a);i<(b);++i)

template<class tt>
struct ab{
    virtual tt go(tt)=0;
};

template<class tt>
struct cd:ab<tt>{
    tt go(tt x) override { return x; }
};

template<class tt>
static tt fx(tt x){
    function<tt(tt)> fn = [](tt v)->tt{ return v; };
    return fn(x);
}

class Solution{
public:
    bool hasAllCodes(string s, ii k){

        unordered_set<string> st;

        cd<ii> ob;
        ab<ii>* dp = &ob;

        ii sz = (ii)s.size();
        ii *ps = &sz;

        auto lm = [&](ii id){
            string *pp = reinterpret_cast<string*>(&s);
            st.insert(pp->substr(id,fx(k)));
        };

        fr(i,0,(*ps)-k+1){
            lm(i);
        }

        ii ex = dp->go((ii)pow(2.0,(double)k));
        ii *pe = &ex;

        return (st.size()==(size_t)(*pe)) ? true : false;
    }
};