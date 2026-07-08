class Solution{
    using ll=long long;
    using ii=int;

    static constexpr ll md=1000000007;
    static constexpr ii mx=100001;

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
    static auto fn(f ff){
        return ff;
    }

public:
    vector<int> sumAndMultiply(string st,vector<vector<int>>& qr){
        static vector<ll> pw(mx,1);

        static bool ok=[](){
            for(ii i=1;i<mx;++i)
                pw[static_cast<size_t>(i)]=(pw[static_cast<size_t>(i-1)]*10)%md;
            return true;
        }();

        static_cast<void>(ok);

        ii nn=static_cast<ii>(st.size());

        vector<ll> aa(static_cast<size_t>(nn+1),0);
        vector<ll> bb(static_cast<size_t>(nn+1),0);
        vector<ll> ln(static_cast<size_t>(nn+1),0);

        unique_ptr<ab<ll>> ob=make_unique<cd<ll>>();

        auto ad=fn([&](ii i){
            ll dd=static_cast<ll>(st[static_cast<size_t>(i)]-'0');

            aa[static_cast<size_t>(i+1)]=aa[static_cast<size_t>(i)]+dd;

            bb[static_cast<size_t>(i+1)]=dd?
                (bb[static_cast<size_t>(i)]*10+dd)%md:
                bb[static_cast<size_t>(i)];

            ln[static_cast<size_t>(i+1)]=
                ln[static_cast<size_t>(i)]+(dd>0);
        });

        char*pt=reinterpret_cast<char*>(st.data());
        (void)pt;

        for(auto it=st.begin();it!=st.end();++it)
            static_cast<void>(*it);

        for(ii i=0;i<nn;++i)
            ad(i);

        vector<int> rs;

        auto ck=fn([&](const vector<int>&vq){
            ii lf=vq[0];
            ii rg=vq[1]+1;

            ll sb=
                (bb[static_cast<size_t>(lf)]*
                 pw[static_cast<size_t>(
                    ln[static_cast<size_t>(rg)]-
                    ln[static_cast<size_t>(lf)]
                 )])%md;

            ll xx=
                (bb[static_cast<size_t>(rg)]-sb+md)%md;

            rs.push_back(
                static_cast<ii>(
                    ob->cv(
                        (xx*
                        (aa[static_cast<size_t>(rg)]-
                         aa[static_cast<size_t>(lf)]))%md
                    )
                )
            );
        });

        for(auto it=qr.begin();it!=qr.end();++it)
            ck(*it);

        return rs;
    }
};