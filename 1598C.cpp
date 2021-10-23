// https://codeforces.com/contest/1598/problem/C
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
	auto start=chrono::high_resolution_clock::now();
	
	//code here

	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		ll sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		double m1=double(sum)/n;
		m1=m1*2;
		if(floor(m1)==m1)
		{
			long long s=floor(m1);
			map<ll, ll> m;
		    for (int i = 0; i < n; i++)
		        m[a[i]]++;
		 
		    long long twice_count = 0;
		 
		    for (int i = 0; i < n; i++) {
		        twice_count += m[s - a[i]];
		 
		        // if (arr[i], arr[i]) pair satisfies the condition,
		        // then we need to ensure that the count is
		        // decreased by one such that the (arr[i], arr[i])
		        // pair is not considered
		        if (s - a[i] == a[i])
		            twice_count--;
		    }
		 
		    // return the half of twice_count
		    cout<<twice_count / 2<<endl;
		}
		else
		{
			cout<<0<<endl;
		}

	}
	
	auto stop=chrono::high_resolution_clock::now();
	auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
	cerr<<duration.count()/1000.0<<" ms\n";
}
