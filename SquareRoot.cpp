// program to find the square root of any number upto 5 decimal place 

#include<iostream>
using namespace std;

// funtion to find square root of number n
double sqrt(int n,int p){
    int s = 0;                       // s = start 
    int e = n;                       // e = end
    double root = 0.0;
    int x=0;

// binarysearch to find the the perfect square root
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mid*mid == n){
            return mid;
        }
        if(mid*mid > n){
            e=mid-1;
        }else{
            s=mid+1;
        }
        x = mid;
    }

    root = x-1;
    int k=1;

    // precision
    double incr = 0.0;       
    for(int i=0; i<p; i++){           
        while(root*root <= n){
            incr += 0.1/k;
            root += incr;
        }
        
        root -= incr;   
        incr /= 10;
        k=k*10;
        incr = 0.1/k;
    
    }
    return root;
}

int main(){
    int n;
    cout<<"enter number :" ;
    cin>>n;
    int p;      //precision value (upto 5 decimal place value)
    cout<<"enter precision value :";
    cin>>p;
    cout<<sqrt(n,p)<<endl;
    return 0;
}
