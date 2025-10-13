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
        ll n, k;
        cin >> n >> k;
        vector<ll> v(k);
        for (ll i = 0; i < k; i++)
        {
            cin >> v[i];
        }
        ll lo = v[0];
        ll fi = v[1] - v[0];

        vector<ll> p;
        if (n == k)
        {
            p.push_back(lo);
        }
        else
        {
            ll diff = n - k + 1;
            ll x = lo / diff;
            if (lo % diff != 0)
            {
                if (lo >= 0)
                {
                    x++;
                }
            }
            p.push_back(x);
        }
        for (ll i = 1; i < k; i++)
        {
            p.push_back(v[i] - v[i - 1]);
        }
        // for (ll i = 0; i < p.size(); i++)
        // {
        //     cout << p[i] << " ";
        // }

        bool flag = true;
        for (ll i = 1; i < p.size(); i++)
        {
            if (p[i] < p[i - 1])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            YES;
        }
        else
        {
            NO;
        }
    }

    return 0;
}