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
        ll n, X;
        cin >> n >> X;
        set<ll> v1;
        set<ll> v2;
        set<ll> v3;
        v1.insert(0);
        v2.insert(0);
        v3.insert(0);
        ll sum = 0;
        bool flag = false;
        // ll sum1 = 0;
        // ll sum2 = 0;
        // ll sum3 = 0;
        ll prev = 0;
        for (ll i = 1; i < n + 1; i++)
        {
            ll v;
            cin >> v;

            v1.insert(v | prev);
            prev=v|prev;
        }
        prev=0;
        for (ll i = 1; i < n + 1; i++)
        {
            ll v;
            cin >> v;
            
            v2.insert(v | prev);
            prev=v|prev;
        }
        prev=0;
        for (ll i = 1; i < n + 1; i++)
        {
            ll v;
            cin>>v;
            v3.insert(v | prev);
            prev=v|prev;
        }

        vector<ll> f1;
        vector<ll> f2;
        vector<ll> f3;
        auto it = v1.begin();
        for (; it != v1.end(); it++)
        {

            if ((*it | X )== X) // checking if *it has less or equal bits than X, then it would be possible to make it X bu OR
            {
                f1.push_back(*it);
            }
        }
        it = v2.begin();
        for (; it != v2.end(); it++)
        {
            if ((*it | X )== X) // checking if *it has less or equal bits than X, then it would be possible to make it X bu OR
            {
                f2.push_back(*it);
            }
        }
        it = v3.begin();
        for (; it != v3.end(); it++)
        {
            if ((*it | X )== X) // checking if *it has less or equal bits than X, then it would be possible to make it X bu OR
            {
                f3.push_back(*it);
            }
        }
        for (ll i = 0; i != f1.size(); i++)
        {
            for (ll j = 0; j != f2.size(); j++)
            {

                for (ll k = 0; k != f3.size(); k++)
                {
                    if ((f1[i] | f2[j] | f3[k]) == X)
                    {
                        // cout << v1[i] << " " << v2[j] << " " << v3[k] << endl;
                        flag = true;
                        goto stat;
                    }
                }
            }
        }
    stat:
        if (flag == true)
        {
            YES;
        }
        else

        {
            NO;
        }
    }

    return 0;
}

