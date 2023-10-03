#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    cout<<endl;
    while(t--){
        // cout<<endl;
        char arr[8][8];
        for(int i=0;i<8;i++){
           for(int j = 0;j<8;j++)
           cin>>arr[i][j];
        }
     for(int i=0;i<8;i++){
        int cnt = 0;
        for(int j=0;j<8;j++){
            if(arr[i][j] != 'R')
            break;
            else
            cnt++;
        }
        if(cnt == 8)
        {
        cout<<"R"<<endl;
        break;
        }
       else
       continue;
    }
     for(int j=0;j<8;j++){
        int cnt = 0;
        for(int i=0;i<8;i++){
            if(arr[i][j] != 'B')
            break;

            else
            cnt++;
        }
        if(cnt == 8)
       {cout<<"B"<<endl;
       break;}
       else
       continue;
    }
    }
    return 0;
}
