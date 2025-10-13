// process was in my head ,but algos were unknow to me . So, i had to use GPT



#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;
#define in3(x, y, z) cin >> x >> y >> z
#define out(x) cout << x << endl

// Modular multiplicative inverse using extended Euclidean algorithm
ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

// Compute nCr % mod
ll nCr(ll n, ll r, const vector<ll>& fact) {
    if (r < 0 || r > n) return 0;
    ll num = fact[n];
    ll denom = (fact[r] * fact[n - r]) % mod;
    return (num * modInverse(denom, mod)) % mod;
}

// Sum of digits in a number (as a string)
ll digisum(string s) {
    ll sum = 0;
    for (char c : s) {
        sum += c - '0';
    }
    return sum;
}

// Check if a number only contains digits a or b
bool check(ll n, ll a, ll b) {
    string s = to_string(n);
    char ca = '0' + a, cb = '0' + b;
    for (char c : s) {
        if (c != ca && c != cb) {
            return false;
        }
    }
    return true;
}

// Precompute factorials up to n
vector<ll> precomputeFactorials(ll n) {
    vector<ll> fact(n + 1, 1);
    for (ll i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    return fact;
}

int main() {
    ll a, b, n;
    in3(a, b, n);

    // Get precomputed factorials
    vector<ll> fact = precomputeFactorials(n);

    // Compute excellent numbers
    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        ll sum = i * b + (n - i) * a; // Sum with i b's and (n-i) a's
        if (check(sum, a, b)) {
            ans = (ans + nCr(n, i, fact)) % mod; // Add number of ways to arrange i b's
        }
    }

    out(ans);
    return 0;
}