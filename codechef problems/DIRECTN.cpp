#include<bits/stdc++.h>
using namespace std;
const int n = 1e6+5;
int arr[n];
void solve ()
{
  int n;
   cin>>n;
   string str;
   cin>>str;
    size_t found = str.find("LL");
    size_t found1 = str.find("RR");
    if (found != string::npos) {cout << "YES" << endl;}
    else if (found1 != string::npos) {
      cout << "YES" << endl;
    }else{
    cout<<"NO"<<endl;
    }
}

int main ()
{
int t=1;
cin>>t;
for(int i = 0; i<t; ++t)
{
    solve (); 
}    
}



