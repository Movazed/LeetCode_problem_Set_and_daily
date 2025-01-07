#include<bits/stdc++.h>
using namespace std;

// Macros for readability
#define MAX 100005
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORR(i, a, b) for(int i = a; i >= b; i--)
#define PB push_back
#define MP make_pair
#define all(x) x.begin(), x.end()
#define si(x) scanf("%d", &x)
#define sii(x, y) scanf("%d%d", &x, &y)
#define PI pair<int, int>

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Sieve of Eratosthenes to precompute smallest prime factors (SPF)
    vector<int> spf(MAX, 0);
    FOR(i, 2, MAX) if(spf[i] == 0){
        spf[i] = i;
        for(int j = 2 * i; j < MAX; j += i) if(spf[j] == 0) spf[j] = i;
    }

    // Input values for N and M
    int N, M;
    cin >> N >> M;

    // Factorization of M!
    vector<PI> m_fact;
    FOR(p, 2, M + 1) if(spf[p] == p){  // Iterate over primes <= M
        int cnt = 0;
        for(ll power = p; power <= M; power *= p){
            cnt += M / power;
            if((ll)p * power > M) break;  // Avoid overflow
        }
        if(cnt > 0) m_fact.PB(MP(p, cnt));
    }

    // Read the array A
    vector<int> A(N);
    for(auto &x : A) cin >> x;

    // Process each element in array A
    FOR(i, 0, N){
        int x = A[i];
        vector<PI> a_fact;

        // Factorize the number x
        if(x > 1){
            for(int p = spf[x]; x > 1; p = spf[x]){
                int cnt = 0;
                while(x % p == 0){
                    cnt++;
                    x /= p;
                }
                a_fact.PB(MP(p, cnt));
            }
        }

        // Two pointers to merge m_fact and a_fact
        int p1 = 0, p2 = 0;
        ll count_div = 1;
        for (int p1 = 0, p2 = 0; p1 < m_fact.size() && p2 < a_fact.size(); ) {
            if (m_fact[p1].first == a_fact[p2].first) {
                ll total = (ll)m_fact[p1].second + a_fact[p2].second;
                count_div = (count_div * (total + 1)) % MOD;
                p1++;
                p2++;
            }
            else if (m_fact[p1].first < a_fact[p2].first) {
                count_div = (count_div * ((ll)m_fact[p1].second + 1)) % MOD;
                p1++;
            }
            else {
                count_div = (count_div * ((ll)a_fact[p2].second + 1)) % MOD;
                p2++;
            }
        }

        // Finish processing the remaining factors
        for(; p1 < m_fact.size(); p1++){
            count_div = (count_div * ((ll)m_fact[p1].second + 1)) % MOD;
        }
        for(; p2 < a_fact.size(); p2++){
            count_div = (count_div * ((ll)a_fact[p2].second + 1)) % MOD;
        }

        // Output the result for this element of the array A
        cout << count_div << (i < N - 1 ? " " : "\n");
    }

    return 0;
}
