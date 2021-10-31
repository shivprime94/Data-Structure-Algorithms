#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    for(int i = 0 ; i <s.length() ; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 32;
        }
        if(s[i] != 'a' &&s[i] != 'y' &&s[i] != 'e' &&s[i] != 'i' &&s[i] != 'o' &&s[i] != 'u'){
            cout<<'.'<<s[i];
        }
    }
    return 0;
}