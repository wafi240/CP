// wafi is too lazy to code
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 998244353;
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

ll fact(ll n)
{
    ll result = 1;
    for (ll i = 2; i <= n; i++)
    {
        result =(result* (i%mod))%mod;
    }
    return result;
}


int main()
{
    tt()
    {
        // cout << "case-" << endl;
        string s;
        cin >> s;

        ll c0 = 0;
        ll c1 = 0;
        if (s.size() == 1)
        {

            cout << 0 << " " << 1 << endl;
            continue;
        }
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                c0++;
            }
            else
            {
                c1++;
            }
        }
        ll count = 1;

        vector<ll> v;
        ll x = 1;
        for (ll i = 1; i < s.size(); i++)
        {

            if (s[i] == s[i - 1])
            {
                count++;
                if (i == s.size() - 1)
                {
                    v.push_back(count);
                }
            }
            else
            {

                v.push_back(count);
                count = 1;
            }
        }

        // for (ll i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
        // nl;

        ll multi = 1;
        for (ll i = 0; i < v.size(); i++)
        {
            multi =(multi* (v[i])%mod)%mod;
        }
        ll sum = 0;
        for (ll i = 0; i < v.size(); i++)
        {
            if (v[i] != 1)
            {
                sum+=v[i]-1;
            }
        }

        ll res = s.size() - sum;

        // cout << multi << " " << res << endl;
        if (c0 == s.size() || c1 == s.size())
        {
            x = fact(s.size());
            cout << s.size() - 1 << " " << x << endl;
        }
        else
        {

            cout << sum << " " << (multi * fact(sum))%mod << endl;
        }
    }

    return 0;
}