#include<iostream>
using namespace std;

int main() {
	// Write your code here
    int num;
    cin>>num;
    int sum_e=0, sum_o=0;
    int m,n;
    
    while(0<num){
        m=num%10;
    	num=num/10;
        if(m%2==0){
            sum_e = sum_e + m;
        }else{
            sum_o=sum_o+m;
           // n=n+1;
        }
    }
    cout<<sum_e<<" "<<sum_o<<endl;
    return 0;	
}
