#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        int a, b;
        cin>>a>>b;
        int f=0;
        int cnt=0;
        
        for(int i=a; i<=b; i++) {
            int s=i;
            int q=i+1;
            int p=i+2;
            int r=i+3;
            
            if((s^q^p^r)==0 && r<=b) {
                f=1;
                cout<<s<<" "<<q<<" "<<p<<" "<<r<<endl;
                break;
            } else {
                cnt++;
                if(cnt > 10)
                    break;
            }
        }
        
        if(f==0)
            cout<<-1<<endl;
    }
return 0;
}