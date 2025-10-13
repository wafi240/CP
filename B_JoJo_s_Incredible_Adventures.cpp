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
int main()
{
    fast;
    tt()
    {
        string s;
        cin >> s;
        ll n = s.size();
        if (s.size() == 1)
        {
            if (s[0] == '0')
            {
                cout << 0 << endl;
                continue;
            }
            else
            {
                cout << 1 << endl;
                continue;
            }
        }
        ll count = 0;
        ll fc = 0;
        ll c0 = 0;
        ll maxcount = -1;
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                break;
            }
            else
            {
                fc++;
            }
        }
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                count++;
            }
            else
            {
                maxcount = max(count, maxcount);
                count = 0;
                c0++;
            }
        }
        // cout<<count<<" "<<fc<<endl;
        if (s[n - 1] == '1')
        {
            count += fc;
        }
        maxcount = max(count, maxcount);
        if (maxcount == 0)
        {
            cout << 0 << endl;
        }
        else if (maxcount == 1)
        {
            cout << 1 << endl;
        }
        else if (c0 == 0)
        {
            cout << n * n << endl;
        }
        else if(maxcount%2==0)
        {
            ll g=maxcount/2;
            cout << g*(g+1) << endl;
        }
        else
        {
            ll g=((maxcount+1)/2);
            cout<<g*g<<endl;
        }
    }
}