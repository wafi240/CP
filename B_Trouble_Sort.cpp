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
        vector<ll> v1(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            v1[i] = v[i];
        }
        map<ll, ll> mp;
        vector<ll> b(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
            mp[v[i]] = b[i];
        }

        sort(v1.begin(), v1.end());
        bool c0 = false;
        bool c1 = false;
        bool sorted = true;
        for (ll i = 0; i < n; i++)
        {
            if (v[i] != v1[i])
            {
                sorted = false;
            }
            ll x = mp[v[i]];
            if (x == 0)
            {
                c0 = true;
            }
            else
            {
                c1 = true;
            }
        }
        if (sorted)
        {
            // cout<<"case-1"<<endl;
            cout << "Yes" << endl;
        }
        else if (c0 && c1)
        {
            // cout<<"case-2"<<endl;
            cout << "Yes" << endl;
        }
        else

        {
            // cout<<"case-3"<<endl;
            cout << "No" << endl;
        }
    }

    return 0;
}