class Solution{
public:

    using ii=int;
    using ll=long long;

    template<class t>
    static t& cv(void* p){ return *reinterpret_cast<t*>(p); }

    template<class t>
    static t* cp(void* p){ return reinterpret_cast<t*>(p); }

    template<class t>
    struct bx{
        virtual t& gt()=0;
        virtual ~bx(){}
    };

    template<class t>
    struct dx:bx<t>{
        t v;
        dx(t x):v(x){}
        t& gt() override{ return v; }
    };

    #define fr(i,a,b) for(ii i=(a);i<(b);++i)
    #define fr0(i,a) for(ii i=0;i<=(a);++i)
    #define gv(x) (*reinterpret_cast<ii*>(&(x)))

    ii maxPathScore(vector<vector<int>>& grid, ii k){

        ii m=(ii)grid.size();
        ii n=(ii)grid[0].size();

        const ii neg=-1000000000;

        vector<vector<ii>> prev(n,vector<ii>(k+1,neg));

        for(ii i=0;i<m;++i){

            vector<vector<ii>> curr(n,vector<ii>(k+1,neg));

            for(ii j=0;j<n;++j){

                ii gain=gv(grid[i][j]);
                ii need=(gain>0?1:0);

                ii limit=min(k,i+j);

                (i==0 && j==0)
                ? (void)(curr[0][0]=0)
                : (void)([&](){

                    for(ii c=need;c<=limit;++c){

                        ii best=neg;

                        (i>0 && gv(prev[j][c-need])!=neg)
                        ? (void)(best=max(best,gv(prev[j][c-need])+gain))
                        : (void)0;

                        (j>0 && gv(curr[j-1][c-need])!=neg)
                        ? (void)(best=max(best,gv(curr[j-1][c-need])+gain))
                        : (void)0;

                        gv(curr[j][c])=best;
                    }

                })();
            }

            *reinterpret_cast<vector<vector<ii>>*>(&prev)=
            move(*reinterpret_cast<vector<vector<ii>>*>(&curr));
        }

        ii ans=neg;

        fr0(c,k)
            ans=max(ans,gv(prev[n-1][c]));

        return ans<0 ? -1 : ans;
    }
};