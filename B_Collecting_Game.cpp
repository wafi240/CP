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
        vector<ll> r(n);
        vector<ll> v1;
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            r[i] = v[i];
        }
        sort(v.begin(), v.end());

        ll sum = 0;
        // for (ll i = 0; i < n; i++)
        // {
        //     cout << v[i] << " ";
        // }
        // nl;
        for (ll i = 0; i < n - 1; i++)
        {
            sum += v[i];
            // cout << sum << " " << v[i + 1] << endl;
            if (sum >= v[i + 1])
            {
                v1.push_back(-1);
            }
            else
            {

                v1.push_back(i);

                // mp[v[i-1]] = count;
            }
        }
        v1.push_back(n - 1);
        // for (ll i = 0; i < n; i++)
        // {
        //     cout << v1[i] << " ";
        // }
        // nl;
        ll maxi = n - 1;
        for (ll i = v1.size() - 1; i >= 0; i--)
        {
            if (v1[i] == -1)
            {
                v1[i] = maxi;
            }
            else
            {
                maxi = v1[i];
            }
            // v1[i]=min(v1[i],i);
        }
        sort(v1.begin(), v1.end());

        // for (ll i = 0; i < n; i++)
        // {
        //     cout << v1[i] << " ";
        // }
        // nl;

        ll i = 0;
        while (i < n)
        {

            mp[v[i]] = v1[i];
            i++;
        }

        for (ll i = 0; i < n; i++)
        {
            cout << mp[r[i]] << " ";
        }
        nl;
    }
    return 0;
}