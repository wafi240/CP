#include<bits/stdc++.h>
using namespace std;
const long long mxn = 2e5 + 9;
vector<long long> g[mxn];
vector<bool> vis(mxn, false);
bool dfs(long long i,long long parent)
{
    vis[i] = true;
    for(long long
        
        child:g[i])
    {
        if(child==parent)
        {
            continue;
        }
        if(vis[child]==true)
        {
            return true;
        }
        if(!vis[child])
        {
            dfs(child, i);
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
  
        for (long long i = 0; i <= n;i++)
        {
            g[i].clear();
            vis[i] = false;
        }
            vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            g[i + 1].push_back(v[i]);
            g[v[i]].push_back(i + 1);
        }
        long long cnt1 = 0;
        long long cnt2 = 0;
        for (long long i = 1; i <= n;i++)
        {
            if(vis[i]==false)
            {
                if(dfs(i,-1))
                {
                    cnt1++;
                }
                cnt2++;
            }
        }
        cout << cnt1 + (cnt2-cnt1 > 0) << " " << cnt2 << endl;
    }
    return 0;
}