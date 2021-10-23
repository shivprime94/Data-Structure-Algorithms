#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,n;
	cin>>t;
	while(t--)
	{
	    long long x=1,y=2,s=0;
	    cin>>n;
	    if(n==1) s=1;
	    else if(n==2) s=2;
	    for(int i=3;i<=n;i++)
	    {
	       s=x+y;
	       x=y;
	       y=s;
	    }
	    cout<<s<<"\n";
	}
	return 0;
}
