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
    tt()
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<ll> p(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        if (n == 1)
        {
            cout << v[0] << endl;
            continue;
        }
        double lo = -1e18, hi = 1e18;

        double ans = hi;
        double pre = 1e9;
        ll count = 0;
        ll mini=1e18;
        while (lo < hi && count < 200)
        {
            double mid = (lo + hi) / 2.0;
            double sum = 0;

            bool ok = true;
            for (ll i = 0; i < n; i++)
            {
                double x = sum + abs(v[i] - mid);
                if (x > pre)
                {
                    ok = false;
                    break;
                }

                sum += x;
            }
            if (ok)
            {
                pre = min(pre,sum);
                ans = mid;
                hi = mid;
            }
            else
            {
                lo = mid;
            }
            count++;
        }
        cout << fixed << setprecision(6) << abs(ans) << endl;
    }
    return 0;
}