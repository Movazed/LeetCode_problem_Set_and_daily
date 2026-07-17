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

    virtual vector<ii> sl(vector<ii>& ar,vector<ll>& qr){

        ii mx=*max_element(ar.begin(),ar.end());

        vector<ii> fq(mx+1,0);
        vector<ll> gc(mx+1,0);

        ii* pa=ar.data();
        void* pv=reinterpret_cast<void*>(pa);
        (void)pv;

        ii nn=static_cast<ii>(ar.size());

        fr(ix,0,nn-1){
            ii* px=pa+ix;
            ++fq[*px];
        }

        for(ii ix=mx;ix>=1;--ix){

            ll sm=0;
            ll ex=0;

            for(ii jx=ix;jx<=mx;jx+=ix){
                sm+=fq[jx];
                ex+=gc[jx];
            }

            gc[ix]=sm*(sm-1)/2-ex;
        }

        partial_sum(gc.begin(),gc.end(),gc.begin());

        vector<ii> rs(static_cast<ii>(qr.size()));

        ii* pq=rs.data();
        ll* qq=qr.data();

        fr(ix,0,static_cast<ii>(qr.size())-1){

            *(pq+ix)=static_cast<ii>(
                upper_bound(gc.begin(),gc.end(),*(qq+ix))-gc.begin()
            );
        }

        return rs;
    }

    virtual ~ij()=default;
};

class Solution{
public:

    vector<int> gcdValues(vector<int>& ar,vector<long long>& qr){

        unique_ptr<ij> lg=make_unique<ij>();

        auto cl=fn([&](vector<ii>& aa,vector<ll>& bb){
            return lg->sl(aa,bb);
        });

        return cl(ar,qr);
    }
};