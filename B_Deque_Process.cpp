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
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll i = 0, j = n - 1;
        string s = "";
        s += "L";
        s += "R";
        i++;
        j--;
        ll pre = v[j + 1];
        vector<ll> v1;
        v1.push_back(v[0]);
        v1.push_back(v[j + 1]);
        while (i < j)
        {
            ll x = v1.size() - 1;

            if (v1[x] < v1[x - 1])
            {
                if (max(v[i], v[j]) < v1[x])
                {

                    v1.push_back(min(v[i], v[j]));
                    v1.push_back(max(v[i], v[j]));

                    if (min(v[i], v[j]) == v[i])
                    {
                        s += "L";
                        s += "R";
                    }
                    else
                    {
                        s += "R";
                        s += "L";
                    }
                }
                else
                {

                    v1.push_back(max(v[i], v[j]));
                    v1.push_back(min(v[i], v[j]));

                    if (max(v[i], v[j]) == v[i])
                    {
                        s += "L";
                        s += "R";
                    }
                    else
                    {
                        s += "R";
                        s += "L";
                    }
                }
            }
            else
            {

                if (min(v[i], v[j]) > v1[x])
                {
                    // max->min
                    v1.push_back(max(v[i], v[j]));
                    v1.push_back(min(v[i], v[j]));

                    if (max(v[i], v[j]) == v[i])
                    {
                        s += "L";
                        s += "R";
                    }
                    else
                    {
                        s += "R";
                        s += "L";
                    }
                }
                else
                {

                    v1.push_back(min(v[i], v[j]));
                    v1.push_back(max(v[i], v[j]));

                    if (min(v[i], v[j]) == v[i])
                    {
                        s += "L";
                        s += "R";
                    }
                    else
                    {
                        s += "R";
                        s += "L";
                    }
                }
            }
            // v1.push_back(pre);
            i++;
            j--;
        }
        if (n % 2 != 0)
        {
            s += "L";
            v1.push_back(v[i]);
        }

        // for (ll i = 0; i < v1.size(); i++)
        // {
        //     cout << v1[i] << " ";
        // }
        // nl;
        // nl;
        // cout << s.size() << endl;
        cout << s << endl;
    }
    return 0;
}