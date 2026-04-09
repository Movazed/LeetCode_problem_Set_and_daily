#include<bits/stdc++.h>
using namespace std;

using ii=int;
using ll=long long;

#define lp(i,a,b) for(ii i=(a);i<=(b);++i)

struct aa{
    virtual void* x(void*,void*)=0;
    virtual ~aa(){}
};

template<class t>
struct bb:aa{
    void* x(void* p,void* q){ return p?q:p; }
};

struct cc{
    virtual ll y(ll,ll,ll)=0;
};

struct dd:cc{
    ll y(ll a,ll b,ll m){
        ll r=1;
        for( ; b>0; b>>=1, a=(a*a)%m )
            r = (b&1? (r*a)%m : r);
        return r;
    }
};

class Solution{
public:
    const ii m = 1000000007;

    ll p(ll a,ll b){
        dd d;
        return d.y(a,b,m);
    }

    ll inv(ll a){
        return p(a,m-2);
    }

    ii xorAfterQueries(vector<ii>& u, vector<vector<ii>>& q){
        bb<ii> z;
        z.x((void*)1,(void*)1);

        ii n=u.size();
        ii lim = sqrt(n);

        unordered_map<ii, vector<vector<ii>>> mp;

        for(auto& t:q){
            ii l=t[0], r=t[1], k=t[2], v=t[3];
            (k>=lim?
                [&](){
                    ii* ptr=&u[l];
                    for(ii i=l;i<=r;i+=k, ptr+=k)
                        (*ptr) = ( (ll)(*ptr) * v ) % m;
                }():
                mp[k].push_back(t)
            );
        }

        for(auto& w:mp){
            ii k=w.first;
            auto& qq=w.second;

            vector<ll> df(n,1);

            for(auto& t:qq){
                ii l=t[0], r=t[1], v=t[3];
                ll* p = df.data() + l;
                *p = ((*p) * v) % m;

                ii st = (r-l)/k;
                ii nx = l + (st+1)*k;

                (nx<n?
                    df[nx]= (df[nx] * inv(v))%m :
                    df[0]=df[0]
                );
            }

            lp(i,0,n-1){
                (i>=k?
                    df[i] = (df[i]*df[i-k])%m :
                    df[i]=df[i]
                );
                u[i] = ( (ll)u[i] * df[i]) % m;
            }
        }

        ii a=0;
        for(auto& v:u) a^=v;
        return a;
    }
};