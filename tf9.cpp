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

    string s;
    cin >> s;
    ll k;
    cin >> k;

    map<ll, vector<ll>> mp;
    for (ll i = 0; i < s.size(); i++)
    {
        mp[s[i] - 'a'].push_back(i);
    }

    set<string> v;
    auto it = mp.begin();
    auto itt = it;

    itt++;
    if (itt == mp.end())
    {
        itt--;
    }
    itt++;
    if (itt == mp.end())
    {
        itt--;
    }
    itt++;
    if (itt == mp.end())
    {
        itt--;
    }
    itt++;
    if (itt == mp.end())
    {
        itt--;
    }
    itt++;

    while (it != itt)
    {
        ll x = it->second.size();
        ll i = 0;
        while (i < x)

        {
            string q = "";
            ll j = it->second[i];
            while (q.size() < 5 && j < s.size())
            {
                q += s[j];
                j++;
                v.insert(q);
            }
            i++;
        }
        it++;
    }

    auto fq = v.begin();
    ll count = 1;
    while (true)
    {
        if (count == k)
        {
            cout << *fq << endl;
            break;
        }
        count++;
        fq++;
    }

    return 0;
}

// ll n;
// cin >> n;

// map<string, ll> mp;
// vector<pair<string, string>> v;
// for (ll i = 0; i < n; i++)
// {
//     string a, b;
//     cin >> a >> b;

//     mp[a]++;
//     mp[b]++;
//     v.push_back(make_pair(a, b));
// }

// auto it = v.begin();
// bool flag = true;
// while (it != v.end())
// {
//     // cout << mp[it->first] << " " << mp[it->second] << endl;
//     if (it->first == it->second)
//     {
//         if(mp[it->first]>2)
//         {
//             flag=false;break;
//         }
//     }
//     else
//     {
//         if(mp[it->first]>1 && mp[it->second]>1)
//         {
//             flag=false;break;
//         }
//     }

//     it++;
// }
// if (flag == true)
// {
//     cout << "Yes" << endl;
// }
// else
// {
//     cout << "No" << endl;
// }
