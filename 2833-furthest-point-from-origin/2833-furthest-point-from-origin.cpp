#include<bits/stdc++.h>
using namespace std;

using ii=int;
using ll=long long;

#define fr(i,a,b) for(ii i=(a);i<(b);++i)

struct bx{
    virtual ii f(ii,ii)=0;
    virtual ~bx(){}
};

template<class t>
struct by:bx{
    ii f(ii a,ii b){
        return a>b?a-b:b-a;
    }
};

template<class t>
struct bz{
    t v;
    bz(t x=0):v(x){}
    operator t(){ return v; }
};

template<class f>
auto mk(f g){
    return [=](auto...x){ return g(x...); };
}

class Solution{
public:
    ii furthestDistanceFromOrigin(string mv){
        ii lf=0,rg=0,bl=0;

        bx* ob=new by<ii>();

        for(char c:mv){
            c=='L' ? lf++ :
            c=='R' ? rg++ :
                     bl++;
        }

        ii an=ob->f(lf,rg)+bl;

        delete ob;
        return an;
    }
};