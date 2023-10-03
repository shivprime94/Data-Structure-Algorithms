//Author: Akash Gautam (@geekblower)
//Date: 09-10-2022
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define GEEKBLOWER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define TEST_CASES create(t);while(t--)
#define SOLUTION solve(); return 0;
#define display(n) cout<<n<<endl;
#define VI vector<int>
#define PB push_back
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define loop(i,a,b,c) for(int i=a;i<b;i+=c)
#define revloop(i,a,b,c) for(int i=a;i>=b;i-=c)
#define start_loop loop(i,0,n,1)
#define start_revloop revloop(i,n,0,1)
#define create(n) int n;cin>>n;
#define def(a,n) int a[n];start_loop cin>>a[i];
#define print(a) for(auto i : a){cout<<i<<" ";}cout<<endl;
#define vector(a,n) VI a;loop(i,0,n,1){int x;cin>>x;a.PB(x);}
inline int GCD(int a,int b){return !b?a:GCD(b,a%b);}
#define MOD 1000000007
bool IPS[10000007];
int fac[10000007];

void segment_sieve_Algo(int a, int b) {
    for(int i=2; i*i<b; i++) {
        if(!IPS[i]) {
            for(int j=2*i; j*j<b; j+=i) {
                IPS[j] = true;
            }
            
            for(int j=max(2LL, (a+i-1)/i)*i; j<b; j+=i) {
                if(fac[j-a]==0) {
                    fac[j-a] = i;
                }
            }
        }
    }
}

int n, m, s;
int a[400001], B[400001], inverse[400001], result[400001];
unordered_map<int, int> Q;

struct node {
   int l, r, id;
} q[100001];

bool cmp(node a, node b) {
   return (B[a.l]^B[b.l]) ? B[a.l]<B[b.l] : ((B[a.l]&1) ? a.r<b.r : a.r>b.r);
}

void add(int x) {
   s = (s*inverse[Q[a[x]]+1]) % MOD;
   Q[a[x]]++;
   s = (s*(Q[a[x]]+1)) % MOD;
}

void del(int x) {
   s = (s*inverse[Q[a[x]]+1]) % MOD;
   Q[a[x]]--;
   s = (s*(Q[a[x]]+1)) % MOD;
}

int32_t main() {
    GEEKBLOWER
    
    cin >> n >> m >> a[1];
    int size=sqrt(n);
	
    loop(i, 1, size+1, 1) {
        loop(j, (i-1)*size+1, i*size+1, 1) {
			B[j]=i;
        }
    }
    
	inverse[0]=1;
    inverse[1]=1;
	
    loop(i, 2, n+2, 1) {
        inverse[i] = MOD-MOD/i*inverse[MOD%i]%MOD;
    }
    
    int minimum=a[1], maximum=a[1];
    
    loop(i, 2, n+1, 1) {
        cin >> a[i];
        minimum = min(minimum, a[i]);
        maximum = max(maximum, a[i]);
    }
    
    minimum = max(1ll, minimum-10);
    maximum += 10;
    segment_sieve_Algo(minimum, maximum);
    
    loop(i, 1, n+1, 1) {
      a[i] = (fac[a[i]-minimum]==0 ? a[i] : fac[a[i]-minimum]);
    }
    
    loop(i, 1, m+1, 1) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    
    sort(q+1, q+1+m, cmp);
    int l=1, r=0;
    s = 1;
    
    loop(i, 1, m+1, 1) {
        int ql = q[i].l;
        int qr = q[i].r;
        
		while(l>ql) {
            add(--l);
        }
        
		while(r<qr) {
            add(++r);
        }
        
		while(l<ql) {
            del(l++);
        }
        
		while(r>qr) {
            del(r--);
        }
        
		result[q[i].id]=s;
	}
    
    loop(i, 1, m+1, 1) {
        display((result[i]+MOD-1) % MOD)
    }
    
    return 0;
}
