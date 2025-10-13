
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
    ll n;
    string s;
    cin >> n;
    cin >> s;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        string s1;
        cin >> s1;

        if (s1.size() == s.size())
        {
            if (s1 == s)
            {
                v.push_back(i + 1);
            }
            else
            {
                ll count = 0;
                ll j = 0;
                while (j < s1.size())
                {
                    if (s1[j] != s[j])
                    {
                        count++;
                    }
                    j++;
                    if (count > 1)
                    {
                        break;
                    }
                }
                if (count <= 1)
                {
                    v.push_back(i + 1);
                }
            }
        }
        else if (s1.size() > s.size())
        {
            ll j = 0, k = 0, count = 0;
            while (j < s.size() && k < s1.size())
            {
                if (s[j] == s1[k])
                {
                    j++;
                    k++;
                }
                else
                {
                    k++;
                    count++;
                }
                if (count > 1)
                {
                    break;
                }
            }
            if (count <= 1)
            {
                v.push_back(i + 1);
            }
        }
        else
        {
            ll j = 0, k = 0, count = 0;
            while (j < s.size() && k < s1.size())
            {
                if (s[j] == s1[k])
                {
                    j++;
                    k++;
                }
                else
                {
                    j++;
                    count++;
                }
                if (count > 1)
                {
                    break;
                }
            }
            if (count <= 1)
            {
                v.push_back(i + 1);
            }
        }
    }
    if (v.size() == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << v.size() << endl;
        for (ll i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        nl;
    }

    return 0;
}

/* ll r = 0;
    tt()
    {
        r++;
        string s1, s2;

        cin >> s1 >> s2;
        ll x = stoll(s1);
        ll n = stoll(s2);
        string a = "";
        a += s2;
        ll len = s2.size();
        ll iteration=100;
        while (len < s1.size() && len < iteration )
        {
            a += s2;
            len++;
        }
        while (stoll(a) % x != 0 && len < iteration )
        {

            a += s2;
            len++;
        }
if(len>=iteration)
{
    cout<<-1<<endl;
    continue;
}
        cout << "Case " << r << ": " << len << endl;
    }
*/