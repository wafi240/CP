// wafi the laura — farming aura
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#define error(...)
#endif
#define ll long long
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
const ll mod = 1e9 + 7;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ot(x) cout << x << '\n'
#define tt    \
    ll t;     \
    cin >> t; \
    while (t--)
#define pb push_back

int main()
{
    fast
        ll n;
    cin >> n;
    vector<ll> v;
    v.pb(1);
    v.pb(2);
    v.pb(5);
    v.pb(10);
    v.pb(20);
    v.pb(50);
    v.pb(100);
    v.pb(200);
    v.pb(500);

    bool f = false;
    for (ll i = v.size() - 1; i >= 0; i--)
    {

        if (n == v[i])
        {
            cout << 1 << endl
                 << v[i] << endl;
            return 0;
        }
    }
    vector<ll> ans;

    if (n % 2 != 0)
    {
        ll d = n / 2;
        for (ll i = 0; i < d; i++)
        {
            ans.pb(2);
        }
        ans.pb(1);
        cout << ans.size() << endl;
        for (ll i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else
    {
        while (n != 0)
        {
            auto it = lower_bound(v.begin(), v.end(), n);
            if (it == v.end() || n % (*it) != 0)
            {
                it--;
            }
            ll lo = it - v.begin();

            ll d = n / v[lo];
            for (ll i = 0; i < d; i++)
            {
                ans.pb(v[lo]);
            }

            n -= (v[lo] * d);
        }
        map<ll, ll> mp;
        for (ll i = 0; i < ans.size(); i++)
        {
            mp[ans[i]]++;
        }
        auto it = mp.begin();
        bool fl = false;
        while (it != mp.end())
        {
            if (it->second % 2 != 0)
            {
                fl = true;
                break;
            }
            it++;
        }
        if (fl)
        {
            cout << ans.size() << endl;
            for (ll i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "splittable" << endl;
        }
    }

    return 0;
}