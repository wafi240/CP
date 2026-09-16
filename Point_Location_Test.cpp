#include <iostream>
using namespace std;
#define ll long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while (t--) {
        ll x1,y1,x2,y2,x3,y3;
        cin >> x1>>y1>>x2>>y2>>x3>>y3;
        ll x = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);


if(x==0)cout<<"TOUCH"<<endl;
else if(x>0)cout<<"LEFT"<<endl;
else cout<<"RIGHT"<<endl;
    }
}