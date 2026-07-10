constexpr int l=18,nx=100001;

using ll=long long;
using ii=int;
using ip=pair<ii,ii>;

ii up[l][nx],ps[nx];
ip xi[nx];

template<class t>
struct ab{
    virtual t cv(const t&x)=0;
    virtual~ab()=default;
};

template<class t>
struct cd:ab<t>{
    t cv(const t&x)override{
        return x;
    }
};

template<class f>
auto fn(f ff){
    return ff;
}

class Solution{
public:

    static ii ct(ii uu,ii vv,ii lg){

        unique_ptr<ab<ii>> ob=make_unique<cd<ii>>();

        ii*pt=reinterpret_cast<ii*>(up);
        (void)pt;

        uu==vv
            ?static_cast<void>(uu=-1)
            :static_cast<void>(0);

        if(uu==-1)
            return 0;

        up[0][uu]>=vv
            ?static_cast<void>(uu=-2)
            :static_cast<void>(0);

        if(uu==-2)
            return 1;

        up[lg-1][uu]<vv
            ?static_cast<void>(uu=-3)
            :static_cast<void>(0);

        if(uu==-3)
            return -1;

        ii st=0;

        auto jp=fn([&](ii j){
            up[j][uu]<vv
                ?static_cast<void>(
                    st+=(1<<j),
                    uu=up[j][uu]
                )
                :static_cast<void>(0);
        });

        for(ii j=lg-1;j>=0;--j)
            jp(j);

        return ob->cv(st+1);
    }

    vector<int> pathExistenceQueries(ii nn,vector<ii>&ar,ii md,vector<vector<ii>>&qr){

        ii lg=static_cast<ii>(bit_width(static_cast<unsigned>(nn)))+1;

        auto cp=fn([&](ii i){
            xi[i]={
                ar[static_cast<size_t>(i)],
                i
            };
        });

        for(ii i=0;i<nn;++i)
            cp(i);

        sort(xi,xi+nn);

        for(ii i=0;i<nn;++i)
            ps[xi[i].second]=i;

        for(ii lf=0,rg=0;lf<nn;++lf){

            while(rg+1<nn&&
                  xi[rg+1].first-
                  xi[lf].first<=md)
                ++rg;

            up[0][lf]=rg;
        }

        for(ii j=1;j<lg;++j)
            for(ii i=0;i<nn;++i)
                up[j][i]=up[j-1][up[j-1][i]];

        vector<int> rs;
        rs.reserve(qr.size());

        for(auto it=qr.begin();it!=qr.end();++it){

            auto [uu,vv]=minmax(
                ps[(*it)[0]],
                ps[(*it)[1]]
            );

            rs.push_back(
                static_cast<ii>(
                    ct(uu,vv,lg)
                )
            );
        }

        return rs;
    }
};