#include<iostream>
using namespace std;
bool prime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false; //if this condition becomes true it will come out of loop and fuction 
        }
    }
    return true;
}
int main(){
 //check no is prime or not
 cout<<prime(5);
}
