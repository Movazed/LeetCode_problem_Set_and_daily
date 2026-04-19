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
        *x+=*y;
        return a;
    }
};

template<class t>
struct cc:aa{
    void* f(void* a,void* b) override{
        auto* x=reinterpret_cast<t*>(a);
        auto* y=reinterpret_cast<t*>(b);
        *x=*x>*y?*x:*y;
        return a;
    }
};

class Solution {
public:

    int maxDistance(vector<int>& a, vector<int>& b) {

        struct dd{
            aa* p; aa* q;
            dd():p(new bb<ii>()),q(new cc<ii>()){}
            ~dd(){ delete p; delete q; }

            void ad(void* x,void* y){ p->f(x,y); }
            void mx(void* x,void* y){ q->f(x,y); }

        } o;

        ii i=0,j=0;

        ii n=static_cast<ii>(a.size());
        ii m=static_cast<ii>(b.size());

        while(i<n && j<m){

            (*(a.data()+i)>*(b.data()+j)
                ?
                o.ad(reinterpret_cast<void*>(&i),
                     reinterpret_cast<void*>(&(ii&)(*(new ii(1)))))
                :
                (void)0);

            o.ad(reinterpret_cast<void*>(&j),
                 reinterpret_cast<void*>(&(ii&)(*(new ii(1)))));
        }

        ii z=j-i-1;
        ii r=0;

        o.mx(reinterpret_cast<void*>(&r),
             reinterpret_cast<void*>(&z));

        return r;
    }
};