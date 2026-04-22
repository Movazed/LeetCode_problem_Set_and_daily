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

template<class x>
struct bb:aa{
    void* f(void* a,void* b) override{
        auto* u=reinterpret_cast<x*>(a);
        auto* v=reinterpret_cast<x*>(b);
        *u+=*v;
        return a;
    }
};

template<class x>
struct cc:aa{
    void* f(void* a,void* b) override{
        auto* u=reinterpret_cast<vector<x>*>(a);
        auto* v=reinterpret_cast<x*>(b);
        u->push_back(*v);
        return a;
    }
};

class Solution {
public:

    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {

        struct dd{
            aa* p; aa* q;
            dd():p(new bb<ii>()),q(new cc<string>()){}
            ~dd(){ delete p; delete q; }

            void ad(void* a,void* b){ p->f(a,b); }
            void ps(void* a,void* b){ q->f(a,b); }

        } o;

        ii n=static_cast<ii>((*(q.data())).size());

        vector<string> z;

        for(auto it=q.begin();it!=q.end();++it){

            for(auto jt=d.begin();jt!=d.end();++jt){

                ii df=0;

                lp(k,0,n){

                    ((*(it->data()+k)!=*(jt->data()+k))
                     ?
                     o.ad(reinterpret_cast<void*>(&df),
                          reinterpret_cast<void*>(&(ii&)(*(new ii(1)))))
                     :
                     (void)0);

                    if(df>2) break;
                }

                if(df<=2){

                    string w=*it;

                    o.ps(reinterpret_cast<void*>(&z),
                         reinterpret_cast<void*>(&w));

                    break;
                }
            }
        }

        return z;
    }
};