// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long a1[], long long a2[], int n, int m) 
        { 
             int i=0,j=0,l=0,k=0;
             long long mn=0;
             mn=max(a1[n-1],a2[m-1]);
             mn++;
             
             while(i<n && j<m && k<(n + m)){
                 long long e1=a1[i]%mn;
                 long long e2=a2[j]%mn;
                 
                 if(e1<=e2){
                     if(k<n)
                         a1[k]+=(e1*mn);
                     else
                         a2[k-n]+=(e1*mn);
                     k++;
                     i++;
                 }
                 else{
                     if(k<n)
                         a1[k]+=(e2*mn);
                     else
                         a2[k-n]+=(e2*mn);
                     k++;
                     j++;
                 }
             }
            while(i<n){
                int e=a1[i]%mn;
                if(k<n)
                    a1[k]+=(e*mn);
                else
                    a2[k-n]+=(e*mn);
                k++;
                i++;
            }
            while(j<m){
                int e=a2[j]%mn;
                if(k<n)
                    a1[k]+=(e*mn);
                else
                    a2[k-n]+=(e*mn);
                k++;
                j++;
            }
            
            for(i=0;i<n;i++)
                a1[i]=a1[i]/mn;
            for(j=0;j<m;j++)
                a2[j]=a2[j]/mn;
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends
