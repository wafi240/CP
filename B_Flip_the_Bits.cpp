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
        string s;
        cin >> s;
        string s2;
        cin >> s2;
        if (s == s2)
        {
            YES;
            continue;
        }

        bool flag = true;
        // if (s[n - 1] != s2[n - 1])
        // {
        //     flag = !flag;
        // }
        ll c0 = 0, c1 = 0;
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
                c0++;
            else
                c1++;
            if (c0 == c1)
            {
                v.push_back(i);
            }
        }
        if (v.size() == 0)
        {
            NO;
            // cout << "cas-1" << endl;
            continue;
        }
        ll j = v.size() - 1;
        if (v[j] < n - 1 && s[n - 1] != s2[n - 1])

        {
            NO;
            continue;
        }
        if (v[j] == n - 1)
        {
            flag = !flag;

            // j--;
        }
      
        
        bool fixi = true;
        for (ll i = n - 1; i >= 0; i--)
        {
            // cout << s[i] << " " << s2[i] << endl;
            if (s[i] == s2[i])
            {
                if (flag == true)
                {
                    // cout << "case-1" << endl;
                    if (v[j] == i)
                    {
                        j--;
                    }
                    continue;
                }
                else
                {
                    if (v[j] < i || j < 0)
                    {
                        fixi = false;
                        // cout << "break" << endl;
                        break;
                    }
                    j--;
                    flag = !flag;
                    if (v[j] == i)
                    {
                        j--;
                    }
                    // cout << "case-2" << endl;
                }
            }
            else
            {
                if (flag == true)
                {
                    if (v[j] < i || j < 0)
                    {
                        fixi = false;
                        // cout << "break2" << endl;
                        break;
                    }
                    j--;
                    flag = !flag;
                    if (v[j] == i)
                    {
                        j--;
                    }
                    // cout << "case-3" << endl;
                }
                else
                {

                    // cout << "case-4" << endl;
                    if (v[j] == i)
                    {
                        j--;
                    }
                    continue;
                }
            }
        }
        if (fixi == true)
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