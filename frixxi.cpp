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
#define vi1(n) vector<int> v(n);
#define vl(n) vector<ll> v(n);
#define vl1(n) vector<ll> v(n);
#define tt()  \
    int t;    \
    cin >> t; \
    while (t--)
#define rep1(a, n) for (int i = a; i < (n); ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(a, m) for (int j = a; j < (m); ++j)
int main()
{

    fast;
    tt()
    {
        ll n, j, k;
        cin >> n >> j >> k;
        vector<ll> v(n);
        ll ele = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i == (j - 1))
            {
                ele = v[i];
            }
        }
        sort(v.begin(), v.end());
        ll same = 0;
        ll less = 0, more = 0;
        ll maxi = *max_element(v.begin(), v.end());
        if (ele == maxi)
        {
            if (k >= 1)
            {
                YES;
                continue;
            }
            else
            {
                NO;
                continue;
            }
        }
        for (ll i = 0; i < n - 1; i++)
        {
            if (v[i] < ele)
            {
                less++;
            }
            else if (v[i] == ele)
            {
                same++;
            }
            else
            {
                more++;
            }
        }
        ll total = more + less;
        if (same > 1)
        {

            total = total + (same - 1);
        }
        // cout << less << " " << same << " " << more << " " << total << endl;
        if (n - total > k)
        {
            NO;
        }
        else
        {
            YES;
        }
    }
    return 0;
}