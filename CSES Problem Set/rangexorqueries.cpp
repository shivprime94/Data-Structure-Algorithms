#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<ll> pre(n,0);//build a prefix array
    pre[0]=a[0];
    for(ll i=1;i<n;i++)
    {
        pre[i]=(pre[i-1]^a[i]);
    }

    while(q--)
    {
        ll s,e;
        cin>>s>>e;
        s-=1;e-=1;
        if(s==0)
        {
            cout<<pre[e]<<endl;
        }
        else
        {
            cout<<(pre[e]^pre[s-1])<<endl;
        }
    }
}
 
int main()
{
    int t;
    // cin>>t;
    t=1;
    while(t--)
    solve();
}
