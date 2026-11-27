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
virtual ii sl(vector<vector<ii>>&a,ii b){
ii n=static_cast<ii>(a.size()),tp=0;
fr(i,0,n-1)tp=max(tp,a[i][0]);
vector<ii>hv(tp+1),gn(tp+1);
fr(i,0,n-1)hv[a[i][0]]++;
fr(i,1,tp){
ii j=i;
while(j<=tp){
gn[i]+=hv[j];
j+=i;
}
}
ii ch=INT_MAX;
fr(i,0,n-1)ch=min(ch,a[i][1]);
vector<ii>bt(b+1);
fr(i,0,b)bt[i]=i/ch;
fr(i,0,n-1){
ii fc=a[i][0],pr=a[i][1],g=gn[fc];
(g>pr/ch)?static_cast<void>([&](){
ii j=b;
while(j>=pr){
bt[j]=max(bt[j],bt[j-pr]+g);
--j;
}
}()):static_cast<void>(0);
}
return bt[b];
}
virtual~ij()=default;
};
class Solution{
unique_ptr<ij>lg;
public:
Solution():lg(make_unique<ij>()){}
int maximumSaleItems(vector<vector<int>>&items,int budget){
return lg->sl(items,budget);
}
};