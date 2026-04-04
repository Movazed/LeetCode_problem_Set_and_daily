#include<bits/stdc++.h>
using namespace std;

#define fl(i,a,b) for(int i=(a);i<(b);++i)

template<class t> struct q{ t x; q(t y):x(y){} t operator()(){return x;} };

struct w{ virtual int g(int,int)=0; };
struct e:w{ int g(int a,int b){return a+b;} };

class Solution {
public:
    string decodeCiphertext(string s, int r0) {
        return s.empty() ? s : ([&](){
            
            int n = s.size();
            int c0 = (n + r0 - 1) / r0;

            const char *p = s.data();
            string o;

            auto f=[&](auto u){return q<int>(u)();};

            fl(i,0,c0){
                int r=0,c=i;
                auto t=[&](){
                    while(r<r0 && c<c0){
                        o.push_back(p[r*c0 + c]);
                        r++; c++;
                    }
                };
                t();
            }

            auto k=[&](){
                while(!o.empty() && o.back()==' ') 
                    o.pop_back();
            };
            k();

            return o;

        }());
    }
};