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
        map<ll, vector<ll>> mp;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            mp[x].push_back(i + 1);
        }
        // for (auto it = mp.begin(); it != mp.end(); ++it)
        // {
        //     ll key = it->first;             // Key (ll)
        //     vector<ll> values = it->second; // Value (vector<ll>)

        //     cout << "Key: " << key << ", Values: ";
        //     for (ll num : values)
        //     {
        //         cout << num << " ";
        //     }
        //     cout << endl;
        // }

        vector<pair<ll, ll>> v;
        ll count = 0;
        auto it = mp.begin();
        auto itt = mp.begin();
        itt++;
        ll i = 0, j = 0;
        bool flag = true;
        while (itt != mp.end())
        {

            while (j < itt->second.size())
            {
                ll mini = min(it->second[0], itt->second[j]);
                ll maxi = max(it->second[0], itt->second[j]);

                j++;
                // cout<<mini<<" "<<maxi<<endl;
                v.push_back({mini, maxi});
            }
            itt++;j=0;
        }
        if (it->second.size() > 1)
        {
            itt--;
            i++;
            ll a = itt->second[0];
            while (i < it->second.size())
            {
                ll mini = min(itt->second[0], it->second[i]);
                ll maxi = max(itt->second[0], it->second[i]);

                i++; // cout<<mini<<" "<<maxi<<endl;
                v.push_back({mini, maxi});
            }
        }
        if (mp.size() == 1)
        {
            NO;
        }
        else
        {
            YES;
            for (ll i = 0; i < v.size(); i++)
            {
                cout << v[i].first << " " << v[i].second << endl;
            }
        }
    }

    return 0;
}