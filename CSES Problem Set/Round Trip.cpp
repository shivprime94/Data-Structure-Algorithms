#include<bits/stdc++.h>
using namespace std;
 
vector<int> ans;
vector<vector<int>> ans1;
 
// int f=0,check=0;
// void dfs(int n,map<int,vector<int>> &adj,vector<int> &v,int parent){
//     if(check) return;
//     v[n]=1;
//     for(auto i:adj[n]){
//         if(f==n){
//             check=1;
//             f=0;
//         }
//         if(check) return;
//         if(v[i]==1 && i!=parent){
//             f=i;
//             ans.push_back(i);
//             break;
//         }
//         if(v[i]==-1) dfs(i,adj,v,n);
//     }
//     if(check) return;
//     if(f==n){
//         check=1;
//         f=0;
//     }
//     if(f) ans.push_back(n);
// }
 
void dfs2(int n,map<int,vector<int>> &adj,vector<int> &v,int parent){
    v[n]=1;
    for(auto i:adj[n]){
        if(v[i]==1 && i!=parent){
            ans.push_back(i);
        }
        if(v[i]==-1){
            ans.push_back(i);
            dfs2(i,adj,v,n);
        }
    }
}
 
bool dfs3(int n,map<int,vector<int>> &adj,vector<int> &v,int parent){
    v[n]=1;
    // cout<<n<<" ";
    // ans.push_back(n);
    for(auto i:adj[n]){
        // if(i==parent) continue;
        if(v[i]==1 && i!=parent){
            // cout<<i;
            ans.push_back(i);
            return true;
        }
        if(v[i]==-1){
            if(dfs3(i,adj,v,n)){
                ans.push_back(i);
                if(n==ans[0]) ans1.push_back(ans);
                return true;
            }
        }
    }
    // ans.pop_back();
    return false;
}
 
int dfs4(int n,map<int,vector<int>> &adj,vector<int> &v,int parent){
    v[n]=1;
    for(auto i:adj[n]){
        if(v[i]==1 && i!=parent){
            ans.push_back(i);
            return i;
        }
        if(v[i]==-1){
            int x=dfs4(i,adj,v,n);
            if(x==n){
                ans.push_back(i);
                ans.push_back(n);
                if(ans.size()>2) ans1.push_back(ans);
                ans.clear();
                return 0;
            }
            if(x){
                ans.push_back(i);
                return x;
            }
        }
    }
    return 0;
}
 
int main(){
    int n,m; cin>>n>>m;
    map<int,vector<int>> adj;
    while (m--)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> v(n+1,-1);
    
    for (int i = 1; i <= n; i++)
    {
        if(v[i]==-1){
            dfs3(i,adj,v,-1);
        }
        cout<<endl;
        if(ans1.size()) break;
    }
        // cout<<endl<<ans1.size()<<endl;
    if(!ans1.size()) cout<<"IMPOSSIBLE";
    else{
        cout<<endl<<ans1[0].size()+1<<endl;
        for(auto i:ans1[0]) cout<<i<<" ";
        cout<<ans1[0][0];
    }
 
    // int f=0;
    // for(auto a:ans1){
    //     map<int,int> m;
    //     for(auto i:a){
    //         m[i]++;
    //         if(m[i]>1 && i!=a[a.size()-1]) f=1;
    //     }
    //     if(!f){
    //         cout<<a.size()<<endl;
    //         for(auto i:a){
    //             cout<<i<<" ";
    //         }
    //         break;
    //     }
    // }
    // if(f || !ans1.size()) cout<<"IMPOSSIBLE";
    return 0;
}
