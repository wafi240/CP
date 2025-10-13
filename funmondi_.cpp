// wafi is too lazy to code
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;cin>>n;vector<ll>v(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    set<ll>s;
    for (ll i = 0; i < n; i++)
    {
        s.insert(v[i]);
    }
    if(s.size()>2)
    {
        cout<<"Impossible"<<endl;
    }
    else{
        
        cout<<"Possible"<<endl;
    }
    
    
    return 0;
}