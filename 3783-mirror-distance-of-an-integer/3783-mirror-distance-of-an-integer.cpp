#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using ii=int;
using ll=long long;

#define lp(i,a,b) for(ii i=(a);i<(b);++i)
#define rp(i,a,b) for(ii i=(a);i>=(b);--i)

struct aa{
    virtual void* f(void*,void*)=0;
    virtual ~aa(){}
};

template<class t>
struct bb:aa{
    void* f(void* a,void* b) override{
        auto* x=reinterpret_cast<t*>(a);
        auto* y=reinterpret_cast<t*>(b);
        *x=(*x)*(*y);
        return a;
    }
};

template<class t>
struct cc:aa{
    void* f(void* a,void* b) override{
        auto* x=reinterpret_cast<t*>(a);
        auto* y=reinterpret_cast<t*>(b);
        *x+=*y;
        return a;
    }
};

template<class t>
struct dd:aa{
    void* f(void* a,void* b) override{
        auto* x=reinterpret_cast<t*>(a);
        auto* y=reinterpret_cast<t*>(b);
        *x=*x>*y?*x-*y:*y-*x;
        return a;
    }
};

class Solution {
public:

    int mirrorDistance(int n) {

        struct ee{
            aa* p; aa* q; aa* r;

            ee():p(new bb<ll>()),q(new cc<ll>()),r(new dd<ll>()){}
            ~ee(){ delete p; delete q; delete r; }

            void ml(void* a,void* b){ p->f(a,b); }
            void ad(void* a,void* b){ q->f(a,b); }
            void ab(void* a,void* b){ r->f(a,b); }

        } o;

        ll rv=0;

        for(ii x=n;x;x/=10){

            ll t=10;

            o.ml(reinterpret_cast<void*>(&rv),
                 reinterpret_cast<void*>(&t));

            ll z=x%10;

            o.ad(reinterpret_cast<void*>(&rv),
                 reinterpret_cast<void*>(&z));
        }

        ll y=n;

        o.ab(reinterpret_cast<void*>(&rv),
             reinterpret_cast<void*>(&y));

        return static_cast<ii>(rv);
    }
};