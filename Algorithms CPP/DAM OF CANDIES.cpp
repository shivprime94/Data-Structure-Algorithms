//@soumyaagr427
#include<bits/stdc++.h> 
using namespace std; 

class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        int curr_area=0;
        int max_area=0;
        int i=0;
        int j=n-1;
        
        while(i<j)
        {
            
            curr_area=(min(height[j],height[i]))*(j-i-1);
            
            
            if(curr_area>=max_area)
                max_area=curr_area;
                
            if(height[i]<=height[j])
                i++;
            else
                j--;
                
        }
        
        return max_area;
    }   
};



int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}  
