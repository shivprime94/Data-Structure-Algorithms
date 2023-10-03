#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;

		if( (a+b==c)|| (a+c==b)||(b+c==a))
		 cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
}
