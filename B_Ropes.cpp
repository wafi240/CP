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
int main()
{

    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    double lo = 0;
    double hi = accumulate(v.begin(), v.end(), 0);

    double ans = 0.0;
    ll iter = 0;
    while (lo <= hi && iter <= 200)
    {
        iter++;
        double mid = lo + (hi - lo) / 2.0;
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            count +=(ll) (v[i]) / (mid*1.0);
        }
        if (count >= k)
        {
            ans = mid;
            lo = mid ;
        }
        else
        {
            hi = mid ;        }
    }

    cout << ans << endl;
    return 0;
}