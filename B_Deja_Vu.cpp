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
void fastIO()
{ios::sync_with_stdio(false);cin.tie(NULL);}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tt()
    {
        ll n1, n2;
        cin >> n1 >> n2;
        vector<ll> v1(n1);
        vector<ll> v2;
        ll maxi = 1LL<<30;
        for (ll i = 0; i < n1; i++)
        {
            cin >> v1[i];
            
            
        }
        for (ll i = 0; i < n2; i++)
        {
            ll x;
            cin >> x;

            if (x >= maxi)
            {
                continue;
            }

            x = 1LL << x;

            if (x < maxi)
            {
                v2.push_back(x);
                maxi=x;//trick is this: boro gula drkr nai
            }
        }
        // sort(v2.begin(), v2.end());
        ll j = 0;
        while (j < v2.size())
        {
            ll i = 0;
            while (i < v1.size())
            {
                if (v1[i] % v2[j] == 0)
                {
                    v1[i] += (v2[j] / 2);
                }
                i++;
            }
            j++;
        }
        for (ll i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
        nl;
    }
    return 0;
}