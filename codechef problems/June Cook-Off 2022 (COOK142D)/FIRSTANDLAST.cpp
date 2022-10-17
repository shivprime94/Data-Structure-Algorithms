#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
	    int n, arr[100000];
	    cin>>n;
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    
	    int max = arr[0] + arr[n-1];
	    
	    for(int i=0; i<n-1; i++) {
	        int temp = arr[i] + arr[i+1];
	        if(temp>max)
	            max = temp;
	    }
	    
	    cout<<max<<endl;
	}
	
	return 0;
}
