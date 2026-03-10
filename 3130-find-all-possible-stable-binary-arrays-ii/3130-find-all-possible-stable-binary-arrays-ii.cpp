#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fr(i,a,b) for(ll i=(a); i<=(b); ++i)

const ll MOD = 1000000007;
const ll MAXN = 1000;

ll fact[MAXN+1];
ll invfact[MAXN+1];

ll modinv(ll n){
    ll x=0,y=1,px=1,py=0;
    ll m=MOD;
    while(m!=0){
        ll q=n/m;
        ll t=n%m;
        n=m;
        m=t;
        ll nx=px-q*x;
        ll ny=py-q*y;
        px=x; x=nx;
        py=y; y=ny;
    }
    return px;
}

ll ncr(ll n,ll r){
    ll* fp = reinterpret_cast<ll*>(fact);
    ll* ip = reinterpret_cast<ll*>(invfact);
    ll num = *(fp+n);
    ll den = (*(ip+r) * *(ip+n-r)) % MOD;
    return (num*den)%MOD;
}

ll splitways(ll n,ll k,ll limit){
    ll total=0,flag=1,remaining=n;
    for(ll j=0;j<=k && k<=remaining;j++){
        ll term = (ncr(k,j) * ncr(remaining-1,k-1)) % MOD;
        total = (total + flag*term + MOD*MOD) % MOD;
        flag=-flag;
        remaining-=limit;
    }
    return total;
}

class Solution {
public:

    int numberOfStableArrays(int zero, int one, int limit) {

        fact[0]=1;
        fr(i,1,MAXN) fact[i]=(fact[i-1]*i)%MOD;

        invfact[MAXN]=modinv(fact[MAXN]);
        for(ll i=MAXN;i>0;i--)
            invfact[i-1]=(invfact[i]*i)%MOD;

        ll start=(min(zero,one)+limit-1)/limit;

        ll prev=0;
        ll curr=splitways(one,start,limit);
        ll next=splitways(one,start+1,limit);

        ll result=0;

        for(ll k=start;k<=zero;k++){
            ll ways=(prev+2*curr+next)%MOD;
            ways=(ways*splitways(zero,k,limit))%MOD;
            result=(result+ways)%MOD;

            prev=curr;
            curr=next;
            next=splitways(one,k+2,limit);
        }

        return (int)result;
    }
};