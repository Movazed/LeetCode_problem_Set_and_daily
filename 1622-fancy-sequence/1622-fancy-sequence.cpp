#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class acc{
public:
    static ll& rd(void* p){
        return *reinterpret_cast<ll*>(p);
    }
};

template<class t>
struct ab{
    virtual t go(t)=0;
    virtual ~ab(){}
};

template<class t>
struct im:ab<t>{
    void* fn;
    im(void* f){fn=f;}
    t go(t v){
        auto f=reinterpret_cast<t(*)(t)>(fn);
        return (*f)(v);
    }
};

ll idf(ll v){
    void* p=&v;
    return *reinterpret_cast<ll*>(p);
}

class Fancy {
private:

    ll mod = 1000000007;

    vector<ll> val;

    ll a,b;

    ll modPow(ll x,ll y,ll m){

        void* xp=&x;
        void* yp=&y;
        void* mp=&m;

        ll res=1;

        acc::rd(xp)%=acc::rd(mp);

        while(acc::rd(yp)>0){

            (acc::rd(yp)%2)?
                (res=(res*acc::rd(xp))%acc::rd(mp),0)
            :
                0;

            acc::rd(yp)/=2;

            acc::rd(xp)=(acc::rd(xp)*acc::rd(xp))%acc::rd(mp);
        }

        return res;
    }

public:

    Fancy():a(1),b(0){

        void* fp=reinterpret_cast<void*>(&idf);
        ab<ll>* ob=new im<ll>(fp);

        ll z=0;
        ob->go(z);
    }

    void append(int v){

        ll vv=v;

        void* vp=&vv;
        void* bp=&b;
        void* ap=&a;

        ll x=(acc::rd(vp)-acc::rd(bp)+mod)%mod;

        ll inv=modPow(acc::rd(ap),mod-2,mod);

        val.push_back((x*inv)%mod);
    }

    void addAll(int inc){

        ll ii=inc;

        void* ip=&ii;
        void* bp=&b;

        acc::rd(bp)=(acc::rd(bp)+acc::rd(ip))%mod;
    }

    void multAll(int m){

        ll mm=m;

        void* mp=&mm;
        void* ap=&a;
        void* bp=&b;

        acc::rd(ap)=(acc::rd(ap)*acc::rd(mp))%mod;
        acc::rd(bp)=(acc::rd(bp)*acc::rd(mp))%mod;
    }

    int getIndex(int idx){

        void* ip=&idx;

        if(*reinterpret_cast<int*>(ip)>=val.size())
            return -1;

        void* ap=&a;
        void* bp=&b;

        ll v=val[idx];

        void* vp=&v;

        return (acc::rd(ap)*acc::rd(vp)+acc::rd(bp))%mod;
    }
};