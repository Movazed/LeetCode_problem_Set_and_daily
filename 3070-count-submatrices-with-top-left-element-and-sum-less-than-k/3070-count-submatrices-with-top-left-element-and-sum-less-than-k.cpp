#include<bits/stdc++.h>
using namespace std;

using ii=int;
using ll=long long;

#define fr(i,a,b) for(ii i=(a);i<(b);++i)

template<class t> struct ab{ virtual t f(void*,void*)=0; virtual ~ab(){} };

template<class t> struct im:ab<t>{
    t f(void* x,void* y){
        auto& g=*reinterpret_cast<vector<vector<ii>>*>(x);
        ii k=*reinterpret_cast<ii*>(y);

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

auto z=[](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'z';
}();

class solution{
public:
    static ii run(vector<vector<ii>>& g,ii k){
        ab<ii>* o=new im<ii>();

        auto l=[](void* a,void* b,void* c)->ii{
            return reinterpret_cast<ab<ii>*>(c)->f(a,b);
        };

        void* p=reinterpret_cast<void*>(&g);
        void* q=reinterpret_cast<void*>(&k);
        void* r=reinterpret_cast<void*>(o);

        return ((ii(*)(void*,void*,void*))l)(p,q,r);
    }
};

class Solution{
public:
    int countSubmatrices(vector<vector<int>>& g,int k){
        struct a{ virtual ii h(void*,void*)=0; };
        struct b:a{
            ii h(void* x,void* y){
                return solution::run(
                    *reinterpret_cast<vector<vector<ii>>*>(x),
                    *reinterpret_cast<ii*>(y)
                );
            }
        };

        a* v=new b();

        void* p=reinterpret_cast<void*>(&g);
        void* q=reinterpret_cast<void*>(&k);

        return v->h(p,q);
    }
};