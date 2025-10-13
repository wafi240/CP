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
        ll n, k;
        cin >> n >> k;
        set<ll> st;
        ll d = -1;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            st.insert(x);
            if (k-1 == i)
            {
                d = x;
            }
        }
        if (st.size() == 1)
        {
            YES;
            continue;
        }
        auto it = st.begin();
        if (*it != d)
        {
            while (*it != d)
            {
                it++;
            }
        }
        auto itt = it;
        itt++;
        bool flag = true;
        while (itt != st.end())
        {
            // cout<<*itt<<" "<<*it<<endl;
            if ((*itt - *it) > d)
            {
                flag = false;
                break;
            }
            it++;
            itt++;
        }
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