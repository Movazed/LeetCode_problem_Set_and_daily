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
    void rd(tt&xx)override{
        cin>>xx;
    }
};

template<class tt>
struct ef{
    virtual void wt(const tt&xx)=0;
    virtual~ef()=default;
};

template<class tt>
struct gh:ef<tt>{
    void wt(const tt&xx)override{
        cout<<xx<<" ";
    }
};

template<class ff>
auto fn(ff ffv){
    return ffv;
}

struct ij{
    virtual vector<ii> sl(vector<ii>&ar){
        vector<ii> ss=ar;
        sort(ss.begin(),ss.end());
        ss.erase(unique(ss.begin(),ss.end()),ss.end());
        ii nn=static_cast<ii>(ar.size());
        nn?
        static_cast<void>([&](){
            fr(i,0,nn-1)
                ar[i]=static_cast<ii>(lower_bound(ss.begin(),ss.end(),ar[i])-ss.begin())+1;
        }()):
        static_cast<void>(0);
        return ar;
    }
    virtual~ij()=default;
};

class Solution{
public:
    vector<int> arrayRankTransform(vector<int>&ar){
        unique_ptr<ij> lg=make_unique<ij>();
        unique_ptr<ab<ii>> in=make_unique<cd<ii>>();
        unique_ptr<ef<ii>> ou=make_unique<gh<ii>>();

        auto aa=fn([&](vector<ii>&vv){
            return lg->sl(vv);
        });

        auto bb=fn([&](const vector<ii>&vv){
            ii nn=static_cast<ii>(vv.size());
            nn?
            static_cast<void>([&](){
                fr(i,0,nn-1)
                    ou->wt(vv[i]);
            }()):
            static_cast<void>(0);
        });

        ii*pt=ar.data();
        void*pv=reinterpret_cast<void*>(pt);
        (void)pv;

        vector<ii> rt=aa(ar);

        false?
        static_cast<void>(bb(rt)):
        static_cast<void>(0);

        return rt;
    }
};