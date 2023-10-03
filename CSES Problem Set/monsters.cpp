#include<bits/stdc++.h>
using namespace std;
 
vector<pair<int,int>> movements={{1,0},{0,1},{-1,0},{0,-1}};
vector<char> path;
bool pathFinder(vector<vector<char>> &mat,pair<int,int> a,pair<int,int> &ans,int n,int m,vector<vector<int>> &visited){
    visited[a.first][a.second]=1;
    if(a==ans){
        return true;
    }
    for(auto j:movements){
        if(a.first+j.first<n && a.first+j.first>=0 && a.second+j.second<m && a.second+j.second>=0){
            if(mat[a.first+j.first][a.second+j.second]=='.' && visited[a.first+j.first][a.second+j.second]==-1){
                if(j.first==1 && j.second==0) path.push_back('D');
                if(j.first==-1 && j.second==0) path.push_back('U');
                if(j.first==0 && j.second==1) path.push_back('R');
                if(j.first==0 && j.second==-1) path.push_back('L');
                if(pathFinder(mat,{a.first+j.first,a.second+j.second},ans,n,m,visited)) return true;
                path.pop_back();
            }
        }
    }
    return false;
}
 
 
int main(){
    int n,m; cin>>n>>m;
    vector<vector<char>> mat(n,vector<char>(m));
    vector<vector<int>> vism(n,vector<int>(m,-1)),visa(n,vector<int>(m,-1)),distm(n,vector<int>(m,INT_MAX)),dista(n,vector<int>(m,INT_MAX));
    vector<pair<int,int>> monsters;
    pair<int,int> a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char temp;
            cin>>temp;
            mat[i][j]=temp;
            if(mat[i][j]=='M') monsters.push_back({i,j}); 
            if(mat[i][j]=='A') a={i,j};
        }
    }
    queue<pair<pair<int,int>,int>> q;
    for(auto i:monsters){
        distm[i.first][i.second]=0;
        vism[i.first][i.second]=1;
        q.push({i,0});
    }
    while (!q.empty())
    {
        auto i=q.front();
        q.pop();
        for(auto j:movements){
            if(i.first.first+j.first<n && i.first.first+j.first>=0 && i.first.second+j.second<m && i.first.second+j.second>=0){
                if(mat[i.first.first+j.first][i.first.second+j.second]=='.' && vism[i.first.first+j.first][i.first.second+j.second]==-1){
                    vism[i.first.first+j.first][i.first.second+j.second]=1;  
                    distm[i.first.first+j.first][i.first.second+j.second]=i.second+1;
                    q.push({{i.first.first+j.first,i.first.second+j.second},i.second+1});
                }
            }
        }
    }
    dista[a.first][a.second]=0;
    visa[a.first][a.second]=1;
    q.push({a,0});    
    while (!q.empty())
    {
        auto i=q.front();
        q.pop();
        for(auto j:movements){
            if(i.first.first+j.first<n && i.first.first+j.first>=0 && i.first.second+j.second<m && i.first.second+j.second>=0){
                if(mat[i.first.first+j.first][i.first.second+j.second]=='.' && visa[i.first.first+j.first][i.first.second+j.second]==-1){
                    visa[i.first.first+j.first][i.first.second+j.second]=1;  
                    dista[i.first.first+j.first][i.first.second+j.second]=i.second+1;
                    q.push({{i.first.first+j.first,i.first.second+j.second},i.second+1});
                }
            }
        }
    }
    int r[2]={0,n-1};
    pair<int,int> ans;
    int check=1;
    for (auto i:r)
    {
        if(!check) break;
        for (int j = 0; j < m; j++)
        {
            if((mat[i][j]=='.' || mat[i][j]=='A') && dista[i][j]<distm[i][j]){
                ans={i,j};
                cout<<"YES"<<endl;
                cout<<dista[i][j]<<endl;
                check=0;
                break;
            }
        }
    }
    int c[2]={0,m-1};
    for (auto j:c)
    {
        if(!check) break;
        for (int i = 0; i < n; i++)
        {
            if((mat[i][j]=='.' || mat[i][j]=='A') && dista[i][j]<distm[i][j]){
                ans={i,j};
                cout<<"YES"<<endl;
                cout<<dista[i][j]<<endl;
                check=0;
                break;
            }
        }
    }
    if(check) cout<<"NO";
    else{
        vector<vector<int>> visited(n,vector<int>(m,-1));
        pathFinder(mat,a,ans,n,m,visited);
        for(auto i: path) cout<<i;
    }
}
