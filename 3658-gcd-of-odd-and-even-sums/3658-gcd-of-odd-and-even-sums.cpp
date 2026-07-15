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

    virtual ii sl(ii nn){

        ii*pn=&nn;
        void*pv=reinterpret_cast<void*>(pn);
        (void)pv;

        auto rt=fn([&]()->ii{
            return *pn;
        });

        return rt();
    }

    virtual~ij()=default;
};

class Solution{
public:

    int gcdOfOddEvenSums(int n){

        unique_ptr<ij>lg=make_unique<ij>();

        return lg->sl(n);
    }
};