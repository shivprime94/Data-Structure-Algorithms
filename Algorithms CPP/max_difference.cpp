#include<bits/stdc++.h>
using namespace std;
int main()
{
  int days,max=0,*A;
  cout<<"Enter no. of days\n";
  cin>>days;
  A=(int*)malloc(days*sizeof(int));
  for(int i=0;i<days;i++)
  {
    cin>>A[i];
  }
  for(int i=0;i<days;i++)
  {
    for(int j=i+1;j<days;j++)
    {
      if(A[j]-A[i]>max)
      {
        max=A[j]-A[i];
      }
    }
  }
  cout<<max;
  return 0;
}
