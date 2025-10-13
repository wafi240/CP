
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
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    fast;
    tt()
    {
        ll n;
        cin >> n;
        set<ll> v;
        vector<ll> v1;
        map<ll, ll> mp;
        ll indx = -1;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.insert(x);
            mp[x] = i + 1;
            if (x == 1)
            {
                indx = i;
            }
        }
        auto it = v.begin();
        for (ll i = 0; i < v.size(); i++)
        {
            v1.push_back(*it);
            it++;
        }

        ll maxi = -1;
        for (ll i = 0; i <v1.size(); i++)
        {
            for (ll j = i+1; j <v1.size(); j++)
            {
                if (gcd(v1[i], v1[j]) == 1)
                {
                    maxi = max(maxi, mp[v1[i]] + mp[v1[j]]);
                    // cout<<i<<" "<<j<<endl;
                }
            }
        }

        if (indx != -1)
            cout << max(maxi, indx + indx + 2) << endl;
        else
            cout << maxi << endl;
    }
    return 0;
}