#include <bits/stdc++.h>
using namespace std;
int main()
{
     int t;
float a,b,c,p,q,r;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>p>>q>>r;
        double ans=(p+q+r)/2;
        if((a+b+c)>ans || (p+b+c)>ans || (a+q+c)>ans || (a+b+r)>ans)
        {
           cout<<"YES"<<endl;
        }
        else
        {
          cout<<"NO"<<endl;
        }
    }
}