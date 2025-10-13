#include <bits/stdc++.h>
using namespace std;
#define ll int
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
int main()
{

    double c;
    cin >> c;
    double lo = 0.0;
    double hi = c;
    ll iter = 0;
    double ans = hi;
    while (lo <= hi && iter <= 200)
    {
        double mid = lo + (hi - lo) / 2.0;
        if (powl(mid, 2) + sqrtl(mid) <= c)
        {
            ans = mid;
            lo = mid;
        }
        else
        {
            hi = mid;
        }
        iter++;
    }
    cout << fixed << setprecision(15) << ans << endl;
}