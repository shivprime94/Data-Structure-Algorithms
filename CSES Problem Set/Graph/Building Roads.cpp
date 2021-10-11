#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct DSU{
    vector<int> P;
    DSU(int n){
        P.resize(n+1);
        for(int i = 1; i <= n; i++){
            P[i] = i;
        }
    }
    int root(int x){
        if(x == P[x])
        return x;
 
        return P[x] = root(P[x]);
    }
    void Union(int a, int b){
        int A = root(a);
        int B = root(b);
        if(A == B)
        return;
        P[A] = B;
    }
};
int main(){
    int n, m;
    cin >> n >> m; 
    DSU D(n);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        D.Union(x,y);
    }
    vector<int> v;
    for(int i = 1; i <= n; i++){
        if(D.P[i] == i){
            v.push_back(i);
        }
    }
    n = v.size();
    cout << n-1 << "\n";
    for(int i = 0; i+1 < n; i++){
        cout << v[i] << " "<< v[i+1] << "\n";
    }
    return 0;
}
