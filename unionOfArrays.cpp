//program to return union of two arraysdisplaying elements of set i.e., union of the two arrays
#include <iostream>
#include<set>
using namespace std;

int main() {
    int n, m;
    //input size of array 1 and array 2
    cin>>n>>m;
    
    int arr1[n],arr2[m];
    //creating a set to store distinct values 
    set<int>s;
    
    for(int i=0;i<n;i++){
    cin>>arr1[i];
    s.insert(arr1[i]);
    }
    
    for(int i=0;i<m;i++){
    cin>>arr2[i];
    s.insert(arr2[i]);
    }
    //displaying elements of set i.e., union of the two arrays
    for(auto i:s)
    cout<<i<<" ";
    
	
	return 0;
}
