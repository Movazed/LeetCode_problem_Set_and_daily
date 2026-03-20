#include<bits/stdc++.h>
using namespace std;

using ii=int;
using ll=long long;

#define fr(i,a,b) for(ii i=(a);i<(b);++i)

template<class t> struct ab{ virtual t f(void*)=0; virtual ~ab(){} };

template<class t> struct im:ab<t>{
    t f(void* x){
        auto& p=*reinterpret_cast<pair<vector<vector<ii>>*,ii>*>(x);
        auto& g=*p.first;
        ii k=p.second;

        ii n=g.size(),m=g[0].size();

        vector<vector<ii>> ans(n-k+1,vector<ii>(m-k+1));
        auto* ap=ans.data();

        fr(i,0,n-k+1){
            map<ii,ii> mp;

            fr(r,i,i+k)
                fr(c,0,k)
                    mp[*((* (g.data()+r)).data()+c)]++;

            fr(c,0,m-k+1){

                (mp.size()>1)?
                (void)([&](){
                    ii mn=1e9;
                    auto it=mp.begin();
                    ii pr=it->first;
                    for(++it;it!=mp.end();++it)
                        mn=min(mn,abs(it->first-pr)),pr=it->first;
                    *((*(ap+i)).data()+c)=mn;
                }())
                :
                (void)(*((*(ap+i)).data()+c)=0);

                (c<m-k)?
                (void)([&](){
                    fr(r,i,i+k){
                        ii v=*((* (g.data()+r)).data()+c);
                        mp[v]--;
                        (mp[v]==0)?mp.erase(v):0;

                        ii nv=*((* (g.data()+r)).data()+(c+k));
                        mp[nv]++;
                    }
                }())
                : (void)0;
            }
        }
        return ans;
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
    static vector<vector<ii>> run(vector<vector<ii>>& g,ii k){
        ab<vector<vector<ii>>>* o=new im<vector<vector<ii>>>();

        auto l=[](void* a,void* b,void* c){
            return reinterpret_cast<ab<vector<vector<ii>>>*>(c)->f(a);
        };

        pair<vector<vector<ii>>*,ii> p{&g,k};

        return ((vector<vector<ii>>(*)(void*,void*,void*))l)(
            reinterpret_cast<void*>(&p),nullptr,o
        );
    }
};

class Solution{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& g,int k){
        struct a{ virtual vector<vector<ii>> h(void*,void*)=0; };
        struct b:a{
            vector<vector<ii>> h(void* x,void* y){
                auto& p=*reinterpret_cast<pair<vector<vector<ii>>*,ii>*>(x);
                return solution::run(*p.first,p.second);
            }
        };

        pair<vector<vector<ii>>*,ii> p{&g,k};
        a* v=new b();

        return v->h(reinterpret_cast<void*>(&p),nullptr);
    }
};