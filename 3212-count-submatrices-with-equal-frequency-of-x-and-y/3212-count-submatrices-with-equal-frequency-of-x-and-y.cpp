#include<bits/stdc++.h>
using namespace std;

using u16=uint16_t;
using u32=uint32_t;

#define fr(i,a,b) for(u16 i=(a);i<(b);++i)

constexpr u32 kmaxw=1024;
constexpr u32 kbias=kmaxw*kmaxw;

struct meow{
    u32 t:31=kbias;
    u32 f:1=0;

    __attribute__((always_inline)) meow& operator+=(const meow& r) noexcept{
        f|=r.f;
        t+=r.t-kbias;
        return *this;
    }

    __attribute__((always_inline)) operator bool() const noexcept{
        return f&(t==kbias);
    }
};

template<class t> struct ab{ virtual t f(void*)=0; virtual ~ab(){} };

template<class t> struct im:ab<t>{
    t f(void* x){
        auto& o=*reinterpret_cast<vector<vector<char>>*>(x);

        meow g[kmaxw];

        u16 w=(u16)(*reinterpret_cast<vector<vector<char>>*>(&o))[0].size();

        meow* p=g;
        fr(i,0,w) *(p+i)=meow{};

        u32 r=0;

        for(auto it=o.begin();it!=o.end();++it){
            meow s{};

            fr(xi,0,w){
                meow* v=(p+xi);
                char c=*((*it).data()+xi);

                bool ix=(c=='X'),iy=(c=='Y');

                meow tmp{ .t=kbias+ix-iy , .f=(ix||iy) };

                *v+= (s+=tmp);

                r+=!!(*v);
            }
        }
        return r;
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
    static u32 run(vector<vector<char>>& g){
        ab<u32>* o=new im<u32>();

        auto l=[](void* a,void* b)->u32{
            return reinterpret_cast<ab<u32>*>(b)->f(a);
        };

        void* p=reinterpret_cast<void*>(&g);
        void* q=reinterpret_cast<void*>(o);

        return ((u32(*)(void*,void*))l)(p,q);
    }
};

class Solution{
public:
    u32 numberOfSubmatrices(const vector<vector<char>>& g){
        struct a{ virtual u32 h(void*)=0; };
        struct b:a{
            u32 h(void* x){
                return solution::run(
                    *reinterpret_cast<vector<vector<char>>*>(x)
                );
            }
        };

        a* v=new b();
        void* p=reinterpret_cast<void*>(
            const_cast<vector<vector<char>>*>(&g)
        );

        return v->h(p);
    }
};