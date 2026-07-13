#include<bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(ii i=(a);i<=(b);++i)

using ll=long long;
using ii=int;

template<class tt>
struct ab{
    virtual void rd(tt&xx)=0;
    virtual~ab()=default;
};

template<class tt>
struct cd:ab<tt>{
    void rd(tt&xx)override{}
};

template<class tt>
struct ef{
    virtual void wt(const tt&xx)=0;
    virtual~ef()=default;
};

template<class tt>
struct gh:ef<tt>{
    void wt(const tt&xx)override{}
};

template<class ff>
auto fn(ff fv){
    return fv;
}

struct ij{

    virtual vector<ii> sl(ii lw,ii hg){

        vector<ii>an;

        string ss="123456789";
        string ls=to_string(lw);
        string hs=to_string(hg);

        ii*pl=&lw;
        ii*ph=&hg;

        void*pv=reinterpret_cast<void*>(pl);
        (void)pv;

        auto ad=fn([&](ii vl){
            an.push_back(vl);
        });

        fr(ix,(ii)ls.size(),(ii)hs.size()){

            fr(jx,0,9-ix){

                string tt=ss.substr(jx,ix);

                ii nm=stoi(tt);

                (nm>=*pl&&nm<=*ph)?
                static_cast<void>(ad(nm)):
                static_cast<void>(0);
            }
        }

        return an;
    }

    virtual~ij()=default;
};

class Solution{
public:

    vector<int> sequentialDigits(int low,int high){

        unique_ptr<ij>lg=make_unique<ij>();

        return lg->sl(low,high);
    }
};