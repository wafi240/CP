#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;
const int MAX = 2005;

vector<ll> fact(MAX), invFact(MAX);

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invFact[MAX - 1] = power(fact[MAX - 1], mod - 2);
    for (int i = MAX - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n)
        return 0;
    return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}

int main() {
    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        if (m == 0) {
            cout << 1 << endl;  // one way to distribute nothing
            continue;
        }

        cout << nCr(n + m - 1, m) % mod << endl;
    }
    return 0;
}
