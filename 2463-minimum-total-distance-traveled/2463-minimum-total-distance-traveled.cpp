#include<bits/stdc++.h>
using namespace std;

using ii=int;
using ll=long long;

#define lp(i,a,b) for(ii i=(a);i<(b);++i)
#define lq(i,a,b) for(ii i=(a);i<=(b);++i)
#define rp(i,a,b) for(ii i=(a);i>=(b);--i)

#define A(x,i) (*(x+i))

template<class t>
struct ba{ virtual void* f(void*,void*)=0; virtual ~ba(){} };

template<class t>
struct bb:ba<t>{
    void* f(void* a,void* b) override{
        return reinterpret_cast<void*>(reinterpret_cast<ll>(a)^reinterpret_cast<ll>(b));
    }
};

template<class t>
struct bc:ba<t>{
    void* f(void* a,void* b) override{
        return reinterpret_cast<void*>(reinterpret_cast<ll>(a)+reinterpret_cast<ll>(b));
    }
};

class Solution {
public:
    long long minimumTotalDistance(vector<int>& r0, vector<vector<int>>& f0) {

        bb<ii>* o0=new bb<ii>();
        bc<ii>* o1=new bc<ii>();

        auto g0=[&](void* x){ return o0->f(x,nullptr); };
        auto g1=[&](void* x){ return o1->f(x,nullptr); };

        sort(r0.begin(), r0.end());
        sort(f0.begin(), f0.end());

        ii n0=r0.size(), m0=f0.size();

        const ll inf0 = (ll)1e18;

        vector<vector<ll>> d0(n0+1, vector<ll>(m0+1, inf0));


        lq(j0,0,m0) A(d0[0].data(), j0)=0;

        lq(j0,1,m0){

            ii p0 = A(f0[j0-1].data(),0);
            ii l0 = A(f0[j0-1].data(),1);

            lq(i0,0,n0){

                A(d0[i0].data(),j0) = A(d0[i0].data(),j0-1);

                ll s0 = 0;

                lq(k0,1,l0){

                    (i0-k0>=0) ?
                    ([&](){

                        s0 += llabs(A(r0.data(),i0-k0) - p0);

                        A(d0[i0].data(),j0) = min(
                            A(d0[i0].data(),j0),
                            A(d0[i0-k0].data(),j0-1) + s0
                        );

                    }(),0)
                    :
                    0;
                }
            }
        }

        g0(reinterpret_cast<void*>(1));
        g1(reinterpret_cast<void*>(2));

        return A(d0[n0].data(),m0);
    }
};