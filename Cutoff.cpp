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
int main()
{

    ll n, x;
    cin >> n >> x;
    vector<ll> v;
    for (ll i = 0; i < n - 1; i++)
    {
        ll d;
        cin >> d;
        v.push_back(d);
    }
    sort(v.begin(), v.end());
    ll sum = accumulate(v.begin(), v.end(), 0);
    ll sum1 = accumulate(v.begin(), v.end(), 0);
    sum = sum - v[0];
    sum1 -= v[n - 2];
    if (sum == x)
    {
        if (sum - v[n - 2] +v[0]== x)
        {
            cout << 0 << endl;
        }
        else 
        {
            
            cout << v[n-2] << endl;
        }
    }
    else if (sum1 >= x)
    {
        cout << 0 << endl;
    }
    else if (sum > x)
    {
        if (sum - v[n - 2] >= x)
        {
            cout << 0 << endl;
        }
        else if (sum - v[n - 2] < x)
        {
            sum -= v[n - 2];
            cout << x - sum << endl;
        }
    }
    else if (sum < x)
    {
        cout << -1 << endl;
    }
    return 0;
}