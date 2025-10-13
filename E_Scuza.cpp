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
ios_base::sync_with_stdio(false);
    
    // Untie cin from cout (don't flush cout before cin)
    cin.tie(nullptr);
    tt()
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        vector<ll> q(k);
        vector<ll> pf(n + 1, 0);
        unordered_map<ll, ll> mp;
        vector<ll> aso;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            pf[i + 1] = pf[i] + v[i];
        }
        for (ll i = 0; i < k; i++)
        {
            cin >> q[i];
            mp[q[i]] = 0;
            aso.push_back(q[i]);
        }
        // auto itt=mp.begin();
        // while (itt!=mp.end())
        // {
        //     cout<<itt->first<<" ";itt++;
        // }
        // nl;

        sort(q.begin(), q.end());
        ll j = 0;
        ll i = 0;
        for (; (i < n) &&(j<k); i++)
        {
            if (q[j] < v[i])
            {
                mp[q[j]] = pf[i];
                j++;
                i--;
            }
        }
        // cout<<"fix; ";
        if (j < k)
        {
            while (j < k)
            {
                mp[q[j]] = pf[i];
                j++;
            }
        }
        ll y = 0;
        while (y < k)
        {
            cout << mp[aso[y]] << " ";
            y++;
        }

        nl;
    }
    return 0;
}