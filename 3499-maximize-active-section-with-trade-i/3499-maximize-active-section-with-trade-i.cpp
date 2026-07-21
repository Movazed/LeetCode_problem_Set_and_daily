#include <bits/stdc++.h>
using namespace std;

using ii=int;
using ll=long long;

template<class ff>
auto fn(ff fv){
    return fv;
}

struct ij{

    ii sl(string& ss){

        ii on=0;

        char* pt=ss.data();

        void* pv=reinterpret_cast<void*>(pt);
        (void)pv;

        ii nn=static_cast<ii>(ss.size());

        for(ii ix=0;ix<nn;++ix){

            char* pc=pt+ix;

            if(*pc=='1'){
                ++on;
            }
        }

        ss='1'+ss+'1';

        nn=static_cast<ii>(ss.size());

        pt=ss.data();

        ii ix=0;
        ii an=on;

        while(ix<nn && *(pt+ix)=='1'){
            ++ix;
        }

        ii lf=0;

        while(ix<nn && *(pt+ix)=='0'){
            ++lf;
            ++ix;
        }

        while(ix<nn){

            ii md=0;

            while(ix<nn && *(pt+ix)=='1'){
                ++md;
                ++ix;
            }

            if(md==0){
                break;
            }

            ii rg=0;

            while(ix<nn && *(pt+ix)=='0'){
                ++rg;
                ++ix;
            }

            if(rg==0){
                break;
            }

            an=max(an,on+lf+rg);

            lf=rg;
        }

        return an;
    }

    virtual ~ij()=default;
};

class Solution {
public:

    int maxActiveSectionsAfterTrade(string s) {

        unique_ptr<ij> lg=make_unique<ij>();

        auto cl=fn([&](string& tt)->ii{
            return lg->sl(tt);
        });

        return cl(s);
    }
};