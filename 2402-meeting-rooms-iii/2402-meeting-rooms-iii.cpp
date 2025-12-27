#define v vector
#define p pair
#define ll long long
#define pq priority_queue
#define f(i,a,b) for(int i=a;i<b;++i)
#define a(x) (x).begin(),(x).end()

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        v<v<int>>& m = meetings;
        sort(a(m));
        pq<p<ll,int>, v<p<ll,int>>, greater<>> b;
        pq<int, v<int>, greater<>> r;
        f(i,0,n) r.push(i);
        v<int> c(n);

        for(auto &x:m){
            ll s=x[0], e=x[1];
            while(!b.empty() && b.top().first<=s)
                r.push(b.top().second), b.pop();

            r.empty()
            ? ([&](){ auto t=b.top(); b.pop(); b.push({t.first+e-s,t.second}); c[t.second]++; })()
            : ([&](){ int y=r.top(); r.pop(); b.push({e,y}); c[y]++; })();
        }

        int x=0;
        f(i,1,n) x=c[i]>c[x]?i:x;
        return x;
    }
};