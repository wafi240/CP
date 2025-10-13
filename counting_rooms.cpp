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
ll arr[1000][1000];
bool visited[1000][1000];
ll counter = 0;
ll n,m;
void dfs(ll x, ll y)
{
    if (visited[x][y] || arr[x][y] == 1 || x<0 ||x>=n || y<0|| y>=m)
    {

        return;
    }
    visited[x][y]=true;
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
    dfs(x - 1, y);
}
int main()
{

    
    cin >> n >> m;
vector<string>p(n);

for (ll i = 0; i < n; i++)
{
   string s;cin>>s;
   p[i]=s; 
}


 arr[n][m];//resize array
 visited[n][m]={0};//resize
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            
            
            if (p[i][j] == '#')
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
            visited[i][j] = false;
        }
    }

   
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if(arr[i][j]==0 && !visited[i][j])
            {
                dfs(i,j);
                counter++;

            }
        }
        

    }
    cout<<counter<<endl;
    

    return 0;
}