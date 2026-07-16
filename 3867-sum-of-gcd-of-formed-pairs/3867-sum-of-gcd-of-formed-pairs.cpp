#include<bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(ii i=(a);i<=(b);++i)

using ii=int;
using ll=long long;

template<class tt>
struct ab{
    virtual void rd(tt& xx)=0;
    virtual ~ab()=default;
};

template<class tt>
struct cd:ab<tt>{
    void rd(tt& xx)override{
        cin>>xx;
    }
};

template<class tt>
struct ef{
    virtual void wt(const tt& xx)=0;
    virtual ~ef()=default;
};

template<class tt>
struct gh:ef<tt>{
    void wt(const tt& xx)override{
        cout<<xx;
    }
};

template<class ff>
auto fn(ff fv){
    return fv;
}

struct ij{

    virtual ll sl(vector<ii>& ar){

        ii mx=0;

        ii* pt=ar.data();
        void* pv=reinterpret_cast<void*>(pt);
        (void)pv;

        ii nn=static_cast<ii>(ar.size());

        ii* px=pt;

        fr(ix,0,nn-1){

            mx=max(mx,*px);

            *px=gcd(*px,mx);

            ++px;
        }

        sort(ar.begin(),ar.end());

        ll an=0;

        ii lf=0;
        ii rg=nn-1;

        while(lf<rg){

            ii* pl=pt+lf;
            ii* pr=pt+rg;

            an+=static_cast<ll>(gcd(*pl,*pr));

            ++lf;
            --rg;
        }

        return an;
    }

    virtual ~ij()=default;
};

class Solution {
public:

    long long gcdSum(vector<int>& ar) {

        unique_ptr<ij> lg=make_unique<ij>();

        auto cl=fn([&](vector<ii>& vr)->ll{
            return lg->sl(vr);
        });

        return cl(ar);
    }
};