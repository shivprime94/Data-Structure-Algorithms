#include <bits/stdc++.h>
using namespace std;
int bits(int a)
{
    int c=0;
    while(a!=0)
    {
        c++;
        a/=2;
    }
    return c;
}
int highest(int n)
{
    int i,a=0;
    for(i=0;i<n;i++)
    {
        a+=(int)pow(2,i);
    }
    return a;
}
int main()
{
    int T,i,N,j,c;
    cin>>T;
    int a[T];
    for(i=0;i<T;i++)
    {
        cin>>N;
        if(N==1||N==2)
        {
            a[i]=1;
            continue;
        }
        else if(N==3)
        {
            a[i]=2;
            continue;
        }
        c=bits(N);
        if(N-highest(c-1)>=highest(c-1)-highest(c-2))
        a[i]=N-highest(c-1);
        else
        a[i]=highest(c-1)-highest(c-2);
    }
    for(i=0;i<T;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}