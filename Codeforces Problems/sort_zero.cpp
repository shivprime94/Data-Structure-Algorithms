#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;cin>>t;
    while(t--)
    {
        
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int pos=n-1;
        while(pos>0&&a[pos]>=a[pos-1]) pos--;
        map<int,int> m;
        for(int i=0;i<pos;i++)
        m[a[i]]=1;
        int in=pos-1;
        for(int i=pos;i<n;i++){
            if(m[a[i]]==1)
            in=i;
        }
        set<int> s;
        for(int i=0;i<=in;i++)
        s.insert(a[i]);
        cout<<s.size()<<endl;
    }
  
 
    return 0;
}
