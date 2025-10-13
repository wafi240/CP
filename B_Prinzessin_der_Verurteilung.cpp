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
        string s;
        cin >> s;

        string s1 = "abcdefghijklmnopqrstuvwxyz";
        string a = "";
        for (ll i = 0; i < s1.size(); i++)
        {
            if (s.find(s1[i]) == -1)
            {
                a= s1[i];
                break;
            }
        }
        if (!a.empty())
        {
            cout << a << endl;
            continue;
        }
        string f = "";
        for (ll i = 0; i < s1.size(); i++)
        {
            f = s1[i];//a
            for (ll j = 0; j < s1.size(); j++)
            {
                string f1 = f;
                f1 += s1[j];//aa
                // cout<<f1<<" "; 
                if (s.find(f1) == -1)
                {
                    a = f1;
                    // cout<<f1<<endl; 
                    
                   
                    goto flag;
                }
            }
        }
        flag:
        if (!a.empty())
        {
            cout << a << endl;
            continue;
        }
        f = "";
        for (ll i = 0; i < s1.size(); i++)
        {
            f = s1[i];//a
            for (ll j = 0; j < s1.size(); j++)
            {
                string f1 = f;
                f1 += s1[j];//aa

                for (ll k = 0; k < s1.size(); k++)

                {
                    string f2 = f1;
                    f2 += s1[k];
                    if (s.find(f2) == -1)
                    {
                        a = f2;
                       goto flag2;
                    }
                }
            }
        }
        flag2:
        if (!a.empty())
        {
            cout << a << endl;
            continue;
        }
    }
    return 0;
}