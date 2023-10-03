#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int x, y;
	    cin>>x>>y;
	    if(y>=x && y<=x+200)
	        cout<<"YES\n";
	    else
	        cout<<"NO\n";
	}
	
	return 0;
}
