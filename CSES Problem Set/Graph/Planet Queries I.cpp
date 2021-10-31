#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<lli,lli> pii;
vector<vi>p;
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    p.resize(31,vector<int>(n+1));
    for(int i=1;i<=n;i++) cin>>p[0][i];
    for(int k=1;k<=30;k++) for(int i=1;i<=n;i++)p[k][i]=p[k-1][p[k-1][i]];
    while(m--){
        int d=-1;
        int now,k;
        cin>>now>>k;
        while(k!=0){
            d++;
            if(1&(k)){
                now=p[d][now];
                
            }
            k=(k>>1);
        }
        cout<<now<<"\n";
    }
 
    return 0;
}