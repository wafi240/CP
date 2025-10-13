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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    int sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        // if (v[i] < 1)
        // {
        //     return cout << -1, 0;
        // }
    }
    if (sum != (n - 1) * 2)
    {
        return cout << -1, 0;
    }
    vector<ll> p;
    vector<ll> p1;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] > 1)
        {
            p.push_back(i);
        }
        else
        {
            p1.push_back(i);
        }
    }
    if(p.size()==1)
    {
        for (ll i = 0; i < p1.size(); i++)
        {
            cout<<p[0]+1<<" "<<p1[i]+1<<endl;
        }
        return 0;
        
    }

    for (ll i = 1; i < (ll)p.size(); i++)
    {
        cout << p[i]+1 << " " << p[i - 1]+1 << endl;
    }

    // for (ll i = 0; i < p1.size(); i++)
    // {
    //     cout << p1[i] << " ";
    // }
    // nl;

    // for (ll i = 0; i < p.size(); i++)
    // {
    //     cout << p[i] << " ";
    // }
    // nl;

    ll indx = 0;
    for (ll i = 0; i < p.size(); i++)
    {
        ll x = v[p[i]];
        ll y ;
        if (i == 0 || i == (ll)p.size() - 1)
        {
            y = 1;
        }
        else
        {
            y=2;
        }
        // cout << "case: " << endl;
        // cout << p[i] << endl;
        // cout << y << " " << x << endl;
        while (y < x && indx < (ll)p1.size())
        {
            cout << p[i]+1 << " " << p1[indx]+1 << endl;
            indx++;
            y++;
        }
    }

    return 0;
}