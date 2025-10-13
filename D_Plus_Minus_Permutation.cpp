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
        ll n, l, r;
        cin >> n >> l >> r;
        if (l == r)
        {
            cout << 0 << endl;
            continue;
        }
        if (max(l, r) % min(l, r) == 0)
        {
            ll x = n / min(l, r);
            ll x1 = n / max(l, r);
            x -= x1;
            ll sum = 0;
            if (min(l, r) == r)
            {

                sum = (x * (x + 1)) / 2;
                cout << -sum << endl;
                continue;
            }
            else
            {

                ll s = (x * (x - 1)) / 2;
                sum = (x * n) - s;
                cout << sum << endl;
                continue;
            }
        }

        ll count = n / l;
        ll count1 = n / r;
        ll g = lcm(l, r);
        ll x;
     
            x = n / g;
        
        count1 -= x;
        count -= x;

        ll sum1 = (count1 * (count1 + 1)) / 2;

        ll s = (count * (count - 1)) / 2;
        ll sum2 = (count * n) - s;

        ll sum = sum2 - sum1;
        cout << sum << endl;
    }

    return 0;
}