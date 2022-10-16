#include "bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin>>n;
        if(n==1)
        {
        cout<<1<<endl;
       continue;
        }
        if((n-2)%4!=2 && (n-2)%4!=3)
        {
            cout<<3<<endl;
        }
        else
        if((n-2)%4==2)
        cout<<n+3<<endl;
        else
        cout<<n<<endl;
    }
}
