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
        deque<ll> v;
        map<ll, ll> mp;
        ll x = (n * (n - 1)) / 2;
        for (ll i = 0; i < x; i++)
        {
            ll q;
            cin >> q;
            mp[q]++;
        }

        auto it = mp.begin();
        ll d = n - 1;
        while (it != mp.end())
        {
            if (it->second > d)
            {
                v.push_back(it->first);
                it->second -= (d);
                d--;
                // cout << "back " << it->first << endl;
                while (it->second> 0)

                {
                    v.push_front(it->first);
                    it->second-=d;
                    d--;
                }
            }
            else
            {
                // cout << "back2 " << it->first << endl;

                v.push_back(it->first);
                d--;
            }

            it++;
        }
        it = mp.end();
        it--;
        if (v.size() < n)
        {
            while (v.size() < n)
            {
                // cout << "size "<<v.size() << endl;
                v.push_back(it->first);
            }
        }
        auto itt = v.begin();
        while (itt != v.end())
        {
            cout << *itt << " ";
            itt++;
        }

        nl;
    }
    return 0;
}