// wafi is too lazy to code
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;
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
ll nCr(ll n, ll r)
{
    if (r > n)
        return 0;
    if (r == 2)
        return (n * (n - 1)) / 2;
    if (r == 1)
        return n;
    if (r == 0 || r == n)
        return 1;

    ll res = 1;
    for (ll i = 1; i <= r; i++)
    {
        res = res * (n - i + 1) / i;
    }
    return res;
}
int main()
{

    ll n, m;
    cin >> n >> m;
    ll maxi = nCr(n - m + 1, 2);
    ll x = n / m;
    ll y = n % m;
// cout<<x<<" "<<y<<endl;
    ll mini;
    mini = y * nCr(x + 1, 2) + (m - y) * nCr(x, 2);

    
    cout << mini << " " << maxi << endl;
    return 0;
}