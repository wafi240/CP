#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, count = 0;
        cin >> n;
        vector<long long> v(n + 1);
        for (long long i = 1; i <= n; i++)
            cin >> v[i];
        for (long long i = 1; i <= n; i++)
        {
            for (long long j = v[i] - i; j <= n; j ++)
            {
                if (j > i && i + j == v[i] * v[j])
                {
                    count++;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}