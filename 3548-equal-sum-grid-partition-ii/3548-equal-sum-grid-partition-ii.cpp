class Solution {
public:
    #define ll long long
    #define fr(i,a,b) for(ll i=(a);i<(b);++i)
    #define eb emplace_back

    template<class t> struct bx{
        virtual t ex(std::vector<std::vector<int>>& g)=0;
        virtual ~bx(){}
    };

    struct cx:bx<bool>{
        std::unordered_map<ll,int> m0,m1,m2,m3;

        bool ck(std::unordered_map<ll,int>& mp,
                std::vector<std::vector<int>>& g,
                int r1,int r2,int c1,int c2,ll df){
            int rr=r2-r1+1,cc=c2-c1+1;
            return rr*cc==1 ? 0 :
                  rr==1 ? ((g[r1][c1]==df||g[r1][c2]==df)?1:0) :
                  cc==1 ? ((g[r1][c1]==df||g[r2][c1]==df)?1:0) :
                  (mp[df]>0?1:0);
        }

        bool ex(std::vector<std::vector<int>>& g) override{
            ll m=g.size(),n=g[0].size(),tt=0;
            m0.clear();m1.clear();m2.clear();m3.clear();
            for(auto &rw:g) for(auto &x:rw) tt+=x,m1[x]++,m3[x]++;

            ll st=0;
            fr(i,0,m-1){
                fr(j,0,n){int v=g[i][j];st+=v;m0[v]++;m1[v]--;}
                ll sb=tt-st;
                if(st==sb) return 1;
                ll df=st>sb?st-sb:sb-st;
                if(st>sb ? ck(m0,g,0,i,0,n-1,df) : ck(m1,g,i+1,m-1,0,n-1,df)) return 1;
            }

            ll sl=0;
            fr(j,0,n-1){
                fr(i,0,m){int v=g[i][j];sl+=v;m2[v]++;m3[v]--;}
                ll sr=tt-sl;
                if(sl==sr) return 1;
                ll df=sl>sr?sl-sr:sr-sl;
                if(sl>sr ? ck(m2,g,0,m-1,0,j,df) : ck(m3,g,0,m-1,j+1,n-1,df)) return 1;
            }

            return 0;
        }
    };

    bool canPartitionGrid(std::vector<std::vector<int>>& g){
        std::unique_ptr<bx<bool>> p(static_cast<bx<bool>*>(new cx));
        return p->ex(g);
    }
};