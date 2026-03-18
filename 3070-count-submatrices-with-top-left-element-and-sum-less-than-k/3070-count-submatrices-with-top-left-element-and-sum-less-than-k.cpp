#include <bits/stdc++.h>
using namespace std;

using ii=int;

#define fr(i,a,b) for(ii i=(a);i<(b);++i)

template<class t> struct ab{ virtual t f(t)=0; virtual ~ab(){} };
template<class t> struct im:ab<t>{ t f(t v){ return v; } };

class solution{
public:
    static ii f(vector<vector<ii>>& g, ii k){
        ii r=g.size(),c=g[0].size();
        ii ct=0,bc=c;

        if(*(g[0].data())>k) return 0;

        ct++;

        fr(j,1,c){
            ii* p=g[0].data();
            *(p+j)+=*(p+j-1);
            (*(p+j)>k)?(bc=j):(ct++);
            if(bc==j) break;
        }

        fr(i,1,r){
            ii* p=g[i].data();
            ii* q=g[i-1].data();

            *p+=*q;
            if(*p>k) break;
            ct++;

            fr(j,1,bc){
                *(p+j)+=*(q+j)+*(p+j-1)-*(q+j-1);
                if(*(p+j)>k){ bc=j; break; }
                ct++;
            }
        }
        return ct;
    }
};

auto init=[](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution{
public:
    int countSubmatrices(vector<vector<int>>& g, int k){
        struct a{ virtual ii h(vector<vector<ii>>&,ii)=0; };
        struct b:a{
            ii h(vector<vector<ii>>& x, ii y){
                return ((ii(*)(vector<vector<ii>>&,ii))(&solution::f))(x,y);
            }
        };
        a* o=new b();
        return o->h(reinterpret_cast<vector<vector<ii>>&>(g),k);
    }
};