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
        map<ll, ll> mp;
        map<ll, ll> mp1;

        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];

            mp[v[i] % 2]++;
            mp1[v[i] % 3]++;
        }

        if (mp.size() == 2)
        {
            cout << 2 << endl;
        }
        else if (mp1.size() == 2)
        {
            cout << 3 << endl;
        }

        else
        {

            ll ans = 2;
            while (true)
            {
                set<ll> st;
                for (ll i = 0; i < n; i++)
                {
                    st.insert(v[i] % ans);
                }
                if (st.size() == 2)
                {
                    break;
                }
                else
                {
                    ans = ans * 2;
                }
            }
            cout << ans << endl;
            // when u go 2,4,8,16.....it takes O(logn);
        }
    }
    return 0;
}