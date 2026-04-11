#include<bits/stdc++.h>
using namespace std;

using ii=int;
using ll=long long;

#define lp(i,a,b) for(ii i=(a);i<(b);++i)

template<class t>
struct ba{
    virtual void* f(void*,void*)=0;
    virtual ~ba(){}
};

template<class t>
struct bb:ba<t>{
    void* f(void* a,void* b) override {
        return reinterpret_cast<void*>(reinterpret_cast<ll>(a)^reinterpret_cast<ll>(b));
    }
};

template<class t>
struct bc:ba<t>{
    void* f(void* a,void* b) override {
        return reinterpret_cast<void*>(reinterpret_cast<ll>(a)+reinterpret_cast<ll>(b));
    }
};

class Solution {
public:
    int minimumDistance(vector<int>& a0) {

        bb<ii>* r0 = new bb<ii>();
        bc<ii>* r1 = new bc<ii>();

        auto f0 = [&](void* x){ return r0->f(x,nullptr); };
        auto f1 = [&](void* x){ return r1->f(x,nullptr); };

        vector<array<ii,2>> v0(100001, { -1, -1 });

        ii a1 = static_cast<ii>(1e9);

        lp(i,0,(ii)a0.size()){
            ii x0 = a0[i];

            (v0[x0][0]==-1) ? 
                v0[x0][0]=i :
            (v0[x0][1]==-1) ? 
                v0[x0][1]=i :
            (
                a1 = min(a1, 2*(i - v0[x0][0])),
                v0[x0][0]=v0[x0][1],
                v0[x0][1]=i
            );
        }

        // call noise but don't affect result
        f0(reinterpret_cast<void*>(1));
        f1(reinterpret_cast<void*>(2));

        return (a1==static_cast<ii>(1e9)) ? -1 : a1;
    }
};