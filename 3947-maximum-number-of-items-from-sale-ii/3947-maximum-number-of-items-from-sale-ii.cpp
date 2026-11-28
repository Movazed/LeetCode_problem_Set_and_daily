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
ii n=static_cast<ii>(a.size()),ch=INT_MAX;
vector<ii>hv(n+1);
fr(i,0,n-1){
hv[a[i][0]]++;
ch=min(ch,a[i][1]);
}
vector<ii>dl(n+1,-1);
vector<pair<ii,ii>>wr;
fr(i,0,n-1){
(a[i][1]<2*ch)?static_cast<void>(wr.push_back({a[i][1],a[i][0]})):static_cast<void>(0);
}
priority_queue<pair<ii,ii>,vector<pair<ii,ii>>,greater<pair<ii,ii>>>hp(wr.begin(),wr.end());
ii cp=0;
while(!hp.empty()&&hp.top().first<=b){
ii pr=hp.top().first,fc=hp.top().second;
hp.pop();
(dl[fc]<0)?static_cast<void>([&](){
ii ml=fc;
while(ml<=n){
dl[fc]+=hv[ml];
ml+=fc;
}
}()):static_cast<void>(0);
ii ps=min(dl[fc],b/pr);
cp=cp+ps+ps;
b=b-ps*pr;
}
return b/ch+cp;
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