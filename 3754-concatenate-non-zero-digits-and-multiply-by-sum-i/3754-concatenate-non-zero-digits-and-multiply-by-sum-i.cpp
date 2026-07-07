class Solution{
    using ll=long long;
    using ii=int;

    template<class t>
    struct ab{
        virtual t cv(const t&x)=0;
        virtual~ab()=default;
    };

    template<class t>
    struct cd:ab<t>{
        t cv(const t&x)override{return x;}
    };

    template<class f>
    static auto fn(f ff){
        return ff;
    };

public:
    ll sumAndMultiply(ii nn){
        unique_ptr<ab<ll>> ob=make_unique<cd<ll>>();

        ll xx=0,ss=0;

        string st=to_string(static_cast<ii>(nn));

        auto ad=fn([&](char cc){
            return cc!='0'?(xx=xx*10+static_cast<ll>(cc-'0'),ss+=static_cast<ll>(cc-'0')):0ll;
        });

        auto it=st.begin();
        char*pt=reinterpret_cast<char*>(&(*it));
        (void)pt;

        for(auto ir=st.begin();ir!=st.end();++ir)ad(*ir);

        return ob->cv(xx*ss);
    }
};