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
        ll c0 = 0;
        ll lo = -1;
        ll hi = -1;
        ll indx = -1;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 0)
            {
                c0++;
                if (indx == -1)
                {
                    indx = i + 1;
                }
            }
        }
        // if (c0 == 1)
        // {
        // }

        
        for (ll i = 0; i < n; i++)
        {
            if (v[i] != i + 1 )
            {
                lo = i;
                break;
            }
        }
        for (ll i = n - 1; i >= 0; i--)
        {
            if (v[i] != i + 1 )
            {
                hi = i;
                break;
            }
        }
        // cout << lo << " " << hi << endl;
        if (lo == -1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << hi - lo + 1 << endl;
        }
    }
    return 0;
}