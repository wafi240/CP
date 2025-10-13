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
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        if (n < 3)
        {
            out(0);
            continue;
        }
        int region = 1;
        int i = 0;
        bool flag = true;
        while (s2[i] == 'x' && s1[i] == 'x')
        {
            i++;
            if (i == n - 2)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            out(0);
            continue;
        }
        int count=0;
        for (int j = i; j < n; j++)
        {
            if (region == 3)
            {
                break;
            }
            if (s2[j] == '.' && s1[j] == '.')
            {
                if (s2[i - 1] == 'x' && s1[i - 1] == 'x')
                {
                    continue;
                }
                else   if (s2[i - 1] == '.' && s1[i - 1] == '.')
                {
                    if (s2[i + 1] == '.' && s1[i + 1] == '.')
                    {
                        count=3;
                        break;
                    }
                    else if (s2[i + 1] == 'x' && s1[i + 1] == '.')
                    {
                        count=3;
                        break;
                    }
                }
                s2[i] = 'x';
                region++;
            }
            else if (s1[i] == '.' && s2[i] == 'x')
            {
                region++;
            }
        }
    }
    return 0;
}