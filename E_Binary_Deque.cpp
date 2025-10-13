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
        ll n, k;
        cin >> n >> k;
        ll x = n;

        x++;
        vector<ll> v;

        ll c1 = 0;
        for (ll i = 0; i < n; i++)
        {

            ll x;
            cin >> x;
            if (x == 1)
            {
                c1++;
                v.push_back(i + 1);
            }
        }

        // for (ll i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
        // nl;

        if (k > c1)
        {
            cout << -1 << endl;
            continue;
        }
        if (k == c1)
        {
            cout << 0 << endl;
            continue;
        }
        ll ans = LLONG_MAX;
        ll i = 0, j = i + 1 + k;
        // if (j >= v.size())
        // {
        //     cout << min({v[i], x - v[i], v[i + 1], x - v[i + 1]}) << endl;
        //     continue;
        // }
        while (j < v.size())
        {
            ll sum = v[i] + x - v[j];
            ans = min(sum, ans);
            i++;
            j++;
        }
        ll diff = c1 - k;
        // cout<<diff<<endl;
        ll ans1 = v[diff-1];
        // cout<<ans1<<endl;
        ll ans2 = x - v[v.size() - diff];
        // cout<<ans2<<endl;
        cout << min({ans1,ans2,ans}) << endl;
    }

    return 0;
}