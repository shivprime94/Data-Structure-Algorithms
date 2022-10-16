#include<iostream>
#include<math.h>

using namespace std;
int prime(int n){
    int count =0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int n;
    cin>>n;
    int flag=0;
    for(int i=2;i<n;i++){
        int k =prime(i);
        if(k==1){
            flag++;
        }
    }
    cout<<flag<<endl;
    return 0;

}