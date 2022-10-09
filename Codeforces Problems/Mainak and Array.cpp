#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"
#define F first
#define S second
#define MP make_pair
#define pb push_back
#define REP(i,n) for(int i = 0 ; i < (n) ; i++)
#define len(x)    ((int)x.size())
#define all(x)    x.begin(),x.end()
using ii=pair<int,int>;

const int mod=(int)(1e9+7);
const int N=100010;
const int inf=(int)(1e18);
const long double pie=acos(-1);


void solve(){
    int n;
    cin>>n;
    int arr[n];
    int mini=1e18,maxi=-1e18;

    REP(i,n){
        cin>>arr[i];
        if(i!=n-1){mini=min(mini,arr[i]);}
        if(i!=0){maxi=max(maxi,arr[i]);}
    }
    int ans=arr[n-1]-arr[0];
    ans=max(ans,arr[n-1]-mini);
    ans=max(ans,maxi-arr[0]);
    for(int i=0;i<n-1;i++){
        ans=max(ans,arr[i]-arr[i+1]);
    }
    cout<<ans<<endl;
}

signed main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    cin>>tt;
    for(int kk=1;kk<=tt;kk++){
          
          solve();
    }
    return 0;
}
