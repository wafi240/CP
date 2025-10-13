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
        for (int i = 1; i < n - 1; i++)
        {
            if (s1[i] == '1')
            {
                if (s2[i - 1] == '0')
                {
                    s1[i] = '0';
                    s2[i - 1] = '1';
                }
                else if (s2[i + 1] == '0')
                {
                    s1[i] = '0';
                    s2[i - 1] = '1';
                }
                else
                {
                    int j = 1;
                    while (true)
                    {
                        if (i + j >= n-1)
                        {
                            break;
                        }
                        if (s2[i + j] == '0')
                        {
                            s1[i] = '0';
                            s2[i + j] = '1';
                            break;
                        }
                        
                        
                        j += 2;
                    }
                }
            }
        }
        if (s1[0] == '1')
        {
            int j = 1;
            while (j < n && j >= 0)
            {
                if (s2[j] == '0')
                {
                    s1[0] = '0';
                    s2[j] = '1';
                    break;
                }
                j += 2;
            }
        }
        if (s1[s1.size() - 1] == '1')
        {
            reverse(s1.begin(), s1.end());
            reverse(s2.begin(), s2.end());
            int j = 1;
            while (j < n && j >= 0)
            {
                if (s2[j] == '0')
                {
                    s1[0] = '0';
                    s2[j] = '1';
                    break;
                }
                j ++;
            }
            reverse(s1.begin(), s1.end());
            reverse(s2.begin(), s2.end());
        }
        // cout << s1 << endl;
        // cout << s2 << endl;
        int x = s1.find('1');
        if (x != -1)
        {
            NO;
        }
        else
        {
            YES;
        }
    }

    return 0;
}