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
        vector<ll> v1(n);
        vector<ll> v2(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v1[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> v2[i];
        }
        vector<ll> p;
        vector<ll> q;
        for (ll i = 0; i < n; i++)
        {
            if (v2[i] - v1[i] < 0)
            {
                p.push_back(v2[i] - v1[i]);
            }
            else
            {
                q.push_back(v2[i] - v1[i]);
            }
        }
        sort(p.begin(), p.end());
        sort(q.begin(), q.end());
        reverse(q.begin(), q.end());
        // reverse(p.begin(), p.end());
        // for (ll i = 0; i < p.size(); i++)
        // {
        //     cout<<p[i]<<" ";
        // }nl;
        // for (ll i = 0; i < q.size(); i++)
        // {
        //     cout<<q[i]<<" ";
        // }nl;
        
        ll i = 0, j = 0;
        if (p.size() == 0)
        {
            cout << q.size() / 2 << endl;
            continue;
        }
        if (q.size() == 0)
        {
            cout << 0 << endl;
            continue;
        }
        ll count = 0;
        while (i < p.size() && j < q.size())
        {
            if (p[i] + q[j] >= 0)
            {
                count++;
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (j < q.size())
        {
            count += (q.size() - j )/2;
        }
        cout << count << endl;
        // nl;
    }

    return 0;
}