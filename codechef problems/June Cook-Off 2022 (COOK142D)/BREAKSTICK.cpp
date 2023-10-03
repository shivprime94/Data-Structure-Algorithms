#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    long long n, x;
	    cin>>n>>x;
	    
	    if(x%2)
	        cout<<"YES\n";
	    else {
	        if((n-x)%2==0)
	            cout<<"YES\n";
	        else
	            cout<<"NO\n";
	    }
	}
	
	return 0;
}
