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

int main()
{

    ll n;
    cin >> n;
    vector<pair<ll, ll>> v;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sum += x;
        v.push_back({x, i + 1});
    }

    vector<ll> p;
    for (ll i = 0; i < n; i++)
    {
        p.push_back(sum - v[i].first);
    }

    sort(v.begin(), v.end());
    sort(p.begin(), p.end());
    // reverse(p.begin(), p.end());
    for (ll i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " ";
    }
    nl;
    for (ll i = 0; i < p.size(); i++)
    {
        cout << p[i] << " ";
    }
    nl;

    vector<ll> w;
    ll j = 0;ll k=v.size()-1;

    for (ll i = 0; i < p.size(); i++,k--)
    {
        if (p[i] % 2 != 0)
        {
            cout << "case-1" << endl;
            continue;
        }
        if (j >= v.size())
        {
            cout << "case-2" << endl;
            break;
        }
        ll q1 = p[i] / 2;
        cout<<q1<<" "<<v[j].first<<endl;
        if (q1 == v[j].first)
        {
            cout << "case-3" << endl;             
        
            cout<<"count incri"<<endl;
            w.push_back(v[i].second);
        }
        else if (q1 > v[j].first)
        {
            cout << "case-4" << endl;
            i--;
            k++;
            j++;
        }
        else
        {
            cout << "case-5" << endl;
            j++;
        }
    }
    cout << w.size() << endl;
    for (ll i = 0; i < w.size(); i++)
    {
        cout << w[i] << " ";
    }
    nl;

    return 0;
}