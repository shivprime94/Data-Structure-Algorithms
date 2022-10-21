#include<bits/stdc++.h>
#define int int64_t
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define M 1000000007
#define EPS 1e-9
#define v(x) vector<x>
#define pii pair<int, int>
#define pb push_back
#define fr first
#define se second
#define all(x) x.begin(), x.end()
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
using namespace std;
//Time complexity : 
//Space complexity : 

struct custom_hash {     
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct pair_hash{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
