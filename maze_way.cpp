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
ll n, m;

ll counter = 0;
ll arr[1000][1000];
bool visited[1000][1000];
void dfs(ll x, ll y)
{
    if (arr[x][y] != 0 || x < 0 || x > n - 1 || y < 0 || y > n - 1)
    {
        return;
    }
    counter++;
    visited[x][y] = 1;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}
int main()
{
    ll k;

    cin >> n >> m >> k;
    arr[n][m];
    vector<string> v(n);
    for (ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v[i] = s;
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {

            if (v[i][j] == '#')
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }
    // first dfs
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                dfs(i, j);
            }
        }
    }

    ll pre = counter;
    counter = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)

        {
            if (k == 0)
            {
                break;
            }
            if (arr[i][j] == 0)
            {
                arr[i][j] = 2;

                if (visited[i + 1][j] == true && i + 1 < n)
                {
                    counter = 0;
                    dfs(i + 1, j);
                    if (counter != pre - 1)
                    {
                        arr[i][j] = 0;
                        k--;
                    }
                }
                else if (visited[i - 1][j] == true && i - 1 >= 0)
                {
                    counter = 0;
                    dfs(i - 1, j);
                    if (counter != pre - 1)
                    {
                        arr[i][j] = 0;
                        k--;
                    }
                }
                else if (visited[i][j + 1] == true && j + 1 < n)
                {
                    counter = 0;
                    dfs(i, j + 1);
                    if (counter != pre - 1)
                    {
                        arr[i][j] = 0;
                        k--;
                    }
                }
                else if (visited[i][j - 1] == true && j - 1 >= 0)
                {
                    counter = 0;
                    dfs(i, j - 1);
                    if (counter != pre - 1)
                    {
                        arr[i][j] = 0;
                        k--;
                    }
                }
                else
                {
                    arr[i][j] = 2;
                    k--;
                }
            }
        }
    }


    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if(v[i][j]==0)
            {
                cout<<'.';
            }
            else if(v[i][j]==1)
            {
                cout<<"#";
            }
            else
            {
                cout<<'X';
            }
        }
        nl;
        
    }
    

    return 0;
}