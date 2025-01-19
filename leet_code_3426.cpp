class Solution {
public:
    long long comb(long long a, long long b, long long mod) {
        if (b > a) return 0;
        long long numer = 1, denom = 1;
        for (long long i = 0; i < b; ++i) {
            numer = numer * (a - i) % mod;
            denom = denom * (i + 1) % mod;
        }

        // Fermat's Little Theorem
        long long denom_inv = 1;
        long long exp = mod - 2;
        while (exp) {
            if (exp % 2) denom_inv = denom_inv * denom % mod;
            denom = denom * denom % mod;
            exp /= 2;
        }
        return numer * denom_inv % mod;
    }

    int distanceSum(int m, int n, int k) {
        int mod = 1e9 + 7;
        long long base = comb(m * n - 2, k - 2, mod);
        long long res = 0;
        for (int d = 1; d < n; ++d) {
            res = (res + 1LL * d * (n - d) % mod * m % mod * m % mod) % mod;
        }
        for (int d = 1; d < m; ++d) {
            res = (res + 1LL * d * (m - d) % mod * n % mod * n % mod) % mod;
        }
        return res * base % mod;
    }
};