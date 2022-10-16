#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize(3, "Ofast", "inline")
 
#include<bits/stdc++.h> 
using namespace std;
using namespace chrono;
#define endl "\n"
 
#define _USE_MATH_DEFINES
#include <cmath>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
 
#define ull long long unsigned
#define int long long int
#define double long double
#define pb push_back
#define mk make_pair
#define ppb pop_back
#define pf  push_front
#define ppf  pop_front
#define all(x) (x).begin(),(x).end()
#define ub upper_bound
#define lb lower_bound
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define sz(x)  (int)((x).size())
#define fr first
#define sc second
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
int const N=2*1e5+10;
//int const INF=1e18;
int mod=1e9+7;
int mod1=998244353;
const int INF=1e15;
// int dx[]={1,1,-1,-1,0,0,-1,1};
// int dy[]={-1,1,-1,1,-1,1,0,0};
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
string S="LRUD";
 #define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 void solve(){
 int n;
 cin>>n;
 vector<int>arr(n);
 rep(i,0,n)cin>>arr[i];
 if(is_sorted(all(arr))){
  cout<<"0"<<endl;
  return;
 }
 int l=0,r=n-1,ct=0;
 while(r>=0 && l<n && r>l){
  while(r>=0 && arr[r]==1)r--;
  while(l<n && arr[l]==0)l++;
  if(r>=0 && l<n && r>l){
    ct++;
    arr[r]=1;
    arr[l]=0;
    r--,l++;
  }
 }
 cout<<ct<<endl;
 return;
}
 
 
 

 
 
 
 
signed main(){
  #ifndef ONLINE_JUDGE
  freopen("INPUT1.txt","r",stdin);
  freopen("out21.txt","w",stdout);
  #endif 
  fastio();
    auto start1 = high_resolution_clock::now();
    int t=1;
    cin>>t;
    // precompute();
    
    //fill_dp();
   // int ct=0;
    while(t--){
      //ct++;
      
      solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cout << "Time: " << duration . count() / 1000 <<"ms"<<endl;
    #endif
  
  return 0;
}
