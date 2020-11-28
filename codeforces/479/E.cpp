// kartikay26
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
#ifdef LOCAL
#include "prettyprint.hpp"
#else
#define debug(x...) 
#define print(x...) 
#endif

template<int MOD> struct Fp {
    int val;
    operator int() { return val; }
    constexpr Fp(int v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() const { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    constexpr bool operator < (const Fp& r) const noexcept {
        return this->val < r.val;
    }
    friend constexpr istream& operator >> (istream& is, Fp<MOD>& x) noexcept {
        is >> x.val;
        x.val %= MOD;
        if (x.val < 0) x.val += MOD;
        return is;
    }
    friend constexpr ostream& operator << (ostream& os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> pow(const Fp<MOD>& a, int n) noexcept {
        if (n == 0) return 1;
        auto t = pow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

const int mod = 1e9+7;
using mint = Fp<mod>;


void solve()
{
    int n, a, b, k; cin >> n >> a >> b >> k; a--, b--;
    mint dp[n];

    dp[a] = 1;

    debug(arr(dp, n));

    for (int i = 0; i < k; ++i) {
        mint new_dp[n+1];
        for (int j = 0; j < n; ++j) {
            // tranisition: dp[j] to dp[j+x], x in (+-) (|j-b| - 1)
            int max_x = abs(j-b) - 1;
            // for (int x = -max_x; x <= max_x; ++x) {
            //     if (!x) continue;
            //     new_dp[j+x] += dp[j];
            // }
            // Range updates
            // j = j - max_x to j - 1
            new_dp[max(j-max_x, 0ll)] += dp[j];
            new_dp[max(j,       0ll)] -= dp[j];
            // j = j+1 to j + max_x
            if (j+1 < n)
            new_dp[j+1]        += dp[j];
            if (j+max_x+1 < n)
            new_dp[j+max_x+1]  -= dp[j];
        }
        int p = 0;
        for (mint& i : new_dp) {
            i += p;
            p = i;
        }
        memcpy(dp, new_dp, sizeof(dp));
        debug(arr(dp, n));
    }

    mint ans;
    for (auto& x : dp) {
        ans += x;
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    print("Time: ", (int)(clock() * 1000. / CLOCKS_PER_SEC), "ms");
    return 0;
}