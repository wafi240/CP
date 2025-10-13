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
        map<ll, vector<ll>, greater<ll>> mp1;
        map<ll, vector<ll>, greater<ll>> mp2;
        map<ll, vector<ll>, greater<ll>> mp3;

        vector<ll> v1(n);
        vector<ll> v2(n);
        vector<ll> v3(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v1[i];
            mp1[v1[i]].push_back(i);
        }

        for (ll i = 0; i < n; i++)
        {
            cin >> v2[i];
            mp2[v2[i]].push_back(i);
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> v3[i];
            mp3[v3[i]].push_back(i);
        }
        auto it = mp1.begin();
        auto itt = mp2.begin();
        auto ittt = mp3.begin();

        vector<pair<ll, ll>> p1;
        vector<pair<ll, ll>> p2;
        vector<pair<ll, ll>> p3;
        ll count = 0;
        ll limit = 3;
        while (count != 3)
        {
            ll x = it->second.size();
            ll i = 0;
            while (i < x && count < 3)
            {
                p1.emplace_back(it->first, it->second[i]);
                i++;
                count++;
            }

            it++;
        }
        count = 0;
        limit = 3;
        while (count != 3)
        {
            ll x = itt->second.size();
            ll i = 0;
            while (i < x && count < 3)
            {
                p2.emplace_back(itt->first, itt->second[i]);
                i++;
                count++;
            }

            itt++;
        }
        count = 0;
        limit = 3;
        while (count != 3)
        {
            ll x = ittt->second.size();
            ll i = 0;
            while (i < x && count < 3)
            {
                p3.emplace_back(ittt->first, ittt->second[i]);
                i++;
                count++;
            }
            ittt++;
        }

        ll sum = 0;
        ll maxi = -1;
        for (ll i = 0; i < p1.size(); i++)
        {
            for (ll j = 0; j < p2.size(); j++)
            {
                if (p1[i].second == p2[j].second)
                {
                    continue;
                }
                for (ll k = 0; k < p3.size(); k++)
                {
                    if (p3[k].second == p2[j].second || p3[k].second == p1[i].second)
                    {
                        continue;
                    }
                    sum = p1[i].first + p2[j].first + p3[k].first;
                    maxi = max(sum, maxi);
                }
            }
        }
        cout << maxi << endl;
    }

    return 0;
}