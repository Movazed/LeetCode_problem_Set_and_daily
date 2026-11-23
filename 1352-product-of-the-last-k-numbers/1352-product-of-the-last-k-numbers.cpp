#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(ii i=(a);i<=(b);++i)
using ll=long long;
using ii=int;
template<class t>struct ab{
virtual void rd(t&x)=0;
virtual~ab()=default;
};
template<class t>struct cd:ab<t>{
void rd(t&x)override{cin>>x;}
};
template<class t>struct ef{
virtual void wt(const t&x)=0;
virtual~ef()=default;
};
template<class t>struct gh:ef<t>{
void wt(const t&x)override{cout<<x;}
};
template<class f>auto fn(f ff){return ff;}
struct ij{
vector<ii> pr;
ij(){pr.push_back(1);}
void ad(ii nm){
(nm==0)?static_cast<void>(pr={1}):static_cast<void>(pr.push_back(pr.back()*nm));
}
ii gp(ii k){
ii n=static_cast<ii>(pr.size());
return (k>=n)?0:pr[n-1]/pr[n-1-k];
}
virtual~ij()=default;
};
class ProductOfNumbers{
unique_ptr<ij> lg;
public:
ProductOfNumbers():lg(make_unique<ij>()){}
void add(ii nm){lg->ad(nm);}
ii getProduct(ii k){return lg->gp(k);}
};