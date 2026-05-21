#include<bits/stdc++.h>
#define fr(i,a,b) for(ii i=a;i<b;i++)
#define pb push_back
using namespace std;
using ii=int;
using ll=long long;

template<class t>
struct aa{
    virtual t f(vector<t>&,vector<t>&)=0;
    virtual ~aa()=default;
};

template<class t>
struct bb:aa<t>{

    struct nd{

        nd*ch[10];

        bool e;

        nd(){

            for(ii *i=reinterpret_cast<ii*>(new ii(0));*i<10;++(*i))

                ch[*i]=nullptr;

            e=0;
        }
    };

    void in(string s,nd*r){

        nd*z=reinterpret_cast<nd*>(r);

        for(char *c=&s[0];c!=&s[0]+s.size();++c){

            ii x=*c-'0';

            if((*reinterpret_cast<nd**>(&z->ch[x]))==nullptr)

                z->ch[x]=reinterpret_cast<nd*>(new nd());

            z=reinterpret_cast<nd*>(z->ch[x]);
        }

        z->e=1;
    }

    ii ck(string s,nd*r){

        nd*z=reinterpret_cast<nd*>(r);

        ii id=0;

        while(id<(ii)s.size()){

            ii x=s[id]-'0';

            if((*reinterpret_cast<nd**>(&z->ch[x]))!=nullptr){

                z=reinterpret_cast<nd*>(z->ch[x]);

                ++id;
            }

            else

                break;
        }

        return *reinterpret_cast<ii*>(&id);
    }

    t f(vector<t>&a,vector<t>&b) override{

        nd*r=reinterpret_cast<nd*>(new nd());

        for(auto *i=reinterpret_cast<typename vector<t>::iterator*>(new typename vector<t>::iterator(b.begin()));(*i)!=b.end();++(*i)){

            string s=to_string(*(*i));

            in(s,r);
        }

        t an=0;

        for(auto *i=reinterpret_cast<typename vector<t>::iterator*>(new typename vector<t>::iterator(a.begin()));(*i)!=a.end();++(*i)){

            string s=to_string(*(*i));

            an=max(an,ck(s,r));
        }

        return *reinterpret_cast<t*>(&an);
    }
};

template<class t>
t zz(t x){return x;}

static auto yy=[](auto &&x)->auto{return std::forward<decltype(x)>(x);};

class Solution {
public:

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        aa<ii>*p=reinterpret_cast<aa<ii>*>(new bb<ii>);

        ii r=p->f(arr1,arr2);

        delete reinterpret_cast<aa<ii>*>(p);

        return r;
    }
};