#include <bits/stdc++.h>
using namespace std;

using ii=int;
using ll=long long;

template<class ff>
auto fn(ff fv){
    return fv;
}

struct ij{

    string sl(string& ss){

        vector<int> fq(256,0);
        vector<bool> sn(256,false);

        int* pf=fq.data();

        void* pv=reinterpret_cast<void*>(pf);
        (void)pv;

        for(char ch:ss){
            ++(*(pf+(unsigned char)ch));
        }

        string st;

        for(char ch:ss){

            --(*(pf+(unsigned char)ch));

            if(sn[(unsigned char)ch]){
                continue;
            }

            while(!st.empty() &&
                  st.back()>ch &&
                  *(pf+(unsigned char)st.back())>0){

                sn[(unsigned char)st.back()]=false;
                st.pop_back();
            }

            st.push_back(ch);
            sn[(unsigned char)ch]=true;
        }

        return st;
    }

    virtual ~ij()=default;
};

class Solution {
public:

    string smallestSubsequence(string s) {

        unique_ptr<ij> lg=make_unique<ij>();

        auto cl=fn([&](string& tt)->string{
            return lg->sl(tt);
        });

        return cl(s);
    }
};