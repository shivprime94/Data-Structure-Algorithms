#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int T;cin>>T;
    for(int i=0;i<T;i++){ 
        int a[4];
        for(int j=0;j<4;j++){ cin>>a[j];}
        sort(a,a+4);
        if(a[0]==a[3]) cout<<0<<endl;
        else if((a[0]==a[2])||(a[1]==a[3])) cout<<1<<endl;
        else cout<<2<<endl;
  
    }

return 0;
}


