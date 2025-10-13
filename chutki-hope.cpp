#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;
#define YES puts("YES")
#define NO puts("NO")
#define tt()  \
    int t;    \
    cin >> t; \
    while (t--)

int main()
{
    tt()
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int count0 = 0, count1 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 0)
            {
                count0++;
            }
            else
            {
                count1++;
            }
        }
        if (count0 == 0 || count1 == 0)
        {
            YES;
            continue;
        }
        int pairy = 0;
        for (int i = 1; i < n; i++)
        {
            if (v[i] == 0 && v[i - 1] == 0)
            {
                pairy++;
                break;
            }
        }
        if (pairy != 0)
        {
            YES;
        }
        else
        {
            NO;
        }
    }
}