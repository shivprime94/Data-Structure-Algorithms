#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int n, d[1000], count=0;
	    cin>>n;
	    
	    for(int i=0; i<n; i++){
	        cin>>d[i];
	        if(d[i] >= 1000)
	            count++;
	    }
	    
	    cout<<count<<endl;
	}
	
	return 0;
}
