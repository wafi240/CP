#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define YES puts("YES")
#define NO puts("NO")
#define in(x) cin >> x
#define in2(x, y) cin >> x >> y;
#define in3(x, y, z) cin >> x >> y >> z;
#define ot(x) cout << x << " ";
#define out(x) cout << x << endl;
#define nl cout << endl;
#define vi(n) vector<int> v(n);
#define vi1(n) vector<int> v1(n);
#define vl(n) vector<ll> v(n);
#define vl1(n) vector<ll> v1(n);
#define tt()  \
    int t;    \
    cin >> t; \
    while (t--)
#define rep1(a, n) for (int i = a; i < (n); ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(a, m) for (int j = a; j < (m); ++j)
const ll inv6 = 166666668; // modular inverse of 6 under mod
const ll inv3 = 333333336; // modular inverse of 3 under mod
#define _mod(a, b) ((a % b) + b) % b
#define ADD_mod(a, b) (((a) + (b)) % mod)
#define SUB_mod(a, b) (((a) - (b) + mod) % mod)
#define MUL_mod(a, b) (((a % mod) * (b % mod)) % mod)
#define POW_mod(a, b) (mod_exp(a, b, mod))

bool isPowerOfTwo(long long n)
{
    if (n <= 0)
        return false; // Negative or zero cannot be a power of 2
    return (n & (n - 1)) == 0;
}
long long highestPowerOfTwo(long long n)
{
    if (n <= 0)
        return 0; // Edge case: no power of 2 exists for n ≤ 0

    // Keep shifting left until we exceed n, then shift back once
    long long power = 1;
    while (power * 2 <= n)
    {
        power *= 2;
    }
    return power;
}

int main()
{

    tt()
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<ll> v1;
        for (ll i = 0; i < n; i++)
        {
            if (v[i] != i)
            {
                v1.push_back(i);
            }
        }
        sort(v1.begin(), v1.end());

        ll ans = -1; // it doesn't change the number when performed AND operation
        for (ll i = 0; i < v1.size(); i++)
        {
            ans = ans & v1[i];
        }
        cout << ans << endl;
    }
    return 0;
}