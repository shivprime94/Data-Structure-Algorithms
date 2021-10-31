#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    int T,x=0;cin>>T;
    string s;
    for(int i=0;i<T;i++){ 
        cin>>s;
        if(s[1]=='-'){x--;}
        else x++;
    }
    cout<<x;
return 0;
}


