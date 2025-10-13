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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tt()
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> v(m + 1, 0);
        bool fg = false;
        vector<set<ll>> dupli;
        for (int i = 0; i < n; i++)
        {
            ll k;
            cin >> k;
            set<ll> st;

            for (ll j = 0; j < k; j++)
            {
                ll x;
                cin >> x;
                if (x >= 1 && x <= m)
                    st.insert(x);
            }

            for (const auto& ele : dupli) {
                if (ele == st) {
                    fg = true;
                    break;
                }
            }

            dupli.push_back(st);

            for (auto it : st)
                v[it]++;
        }

        bool flag = false;
        bool flag1 = false;
        ll c2 = 0;

        for (ll i = 0; i <= m; i++)
        {
            if (v[i] >= 3)
            {
                flag = true;
                break;
            }
            if (v[i] == 2)
            {
                c2++;
                if (c2 >= 2 && n > 2)
                {
                    flag1 = true;

                }
            }
        }

        if (flag || (flag1 && n>2 )|| (fg && n > 2))
            YES;
        else
            NO;
    }

    return 0;
}
