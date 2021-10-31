#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    int T;cin>>T;
    for(int i=0;i<T;i++){ 
        long n,p,k;
        cin>>n>>p>>k;
        int ans;
        int re=(n-1)%k;
        int x=p%k;
        int a = (n-1-re)/k;
        if(x>=0&&x<=re){ans= x*(a+1) + (p-x)/k +1 ;}
        else ans= (a+1)*(re+1) + (x-re-1)*a + (p-x)/k+1;
      
        cout<<ans<<endl;
    }

return 0;
}


