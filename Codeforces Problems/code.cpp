#include<bits/stdc++.h>
using namespace std;
int facto(int p){
    int ans = 1;
    for(int i = p;p>=2;p--){
        ans *= p;
    }
    return ans;
}
int check(vector<int>v, int m){
  // mC2*4!/4 = m!/
  int ans,fans;
  ans = facto(m)/(facto(m-2)*2);
  fans = ans*6;
  return fans;
  
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cout<<check(v,10-n)<<endl;
    }
    return 0;
}
