#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
 
int main(){
    
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    //cin >> t;
 
    while(t--){
       int n, m;
       cin >> n >> m;
       map<int, pair<int, int>> mapp;  //pair <more pow, less pow>
       map<int, int> ans;
       int u, v;
       for(int i=0; i<m; i++){
           cin >> u >> v;
 
           if(u < v){
               mapp[u].first++;
               mapp[v].second++;
           }
           else{
               mapp[u].second++;
               mapp[v].first++;
           }
       }
        for(auto m : mapp){
            if(m.second.first == 0) ans[m.first]++;
        }
        for(int i=1; i<=n; i++){
            if(mapp.count(i) == 0) ans[i]++;
        }
 
       int q;
       cin >> q;
       for(int i=0; i<q; i++){
           int type;
           cin >> type;
 
           if(type == 1){
               cin >> u >> v;
 
                if(u < v){
                    mapp[u].first++;
                    mapp[v].second++;
                }
                else{
                    mapp[u].second++;
                    mapp[v].first++;
                }
 
                if(mapp[u].first != 0) ans.erase(u);
                if(mapp[v].first != 0) ans.erase(v);
           }
           else if(type == 2){
               cin >> u >> v;
               if(u < v){
                   mapp[u].first--;
                   mapp[v].second--;
               }
               else{
                   mapp[u].second--;
                   mapp[v].first--;
               }
               if(mapp[u].first == 0) ans[u]++;
               if(mapp[v].first == 0) ans[v]++;
           }
           else{
               cout << ans.size() << endl;
           }
       }
    }
    return 0;
}
