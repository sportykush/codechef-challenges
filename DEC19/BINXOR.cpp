/*
Author-KUSHAGRA SINGH
Birla Institute of Technology Mesra
CS K18
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
//#define mp make_pair
#define pb emplace_back
#define vll vector<ll>
#define vpll vector< pair <ll,ll> >
#define pll pair <ll,ll>
#define pq priority_queue< int >
#define khtm "\n"
#define F first
#define S second
#define fr(i,a,n) for(i=a;i<n;i++)
#define ALL(x) x.begin(), x.end()
#define frr(i,a,n) for(i=n-1;i>=a;i--)
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcase ll T; cin>>T; while(T--)
const int MAX = 1e6 +2;

/*
important builtin functions
__gcd(value1, value2)
__builtin_ffs(x)
  Number of leading zeroes: __builtin_clz(x)
  Number of trailing zeroes : __builtin_ctz(x)
  Number of set bits: __builtin_popcount(x)
*/

ll i,j,k,l,m,r,n;


ll fac[MAX];

void ini(){
	 fac[0] = 1; 
    for (i=1 ; i<=MAX; i++) 
        fac[i] = fac[i-1]*i%mod;

}

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
ll modInverse(ll n) 
{ 
    return power(n, mod-2, mod); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
ll nCrModPFermat(ll n, ll r) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    // int fac[n+1]; 
    // fac[0] = 1; 
    // for (int i=1 ; i<=n; i++) 
    //     fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r]) % mod * 
            modInverse(fac[n-r]) % mod) % mod; 
} 


int main()
{

  #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

fast
ini();

testcase{
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	ll var1=0;
	fr(i,0,n)
	if(s1[i]=='1')
		var1++;
	
	ll var2=0;
	fr(i,0,n)
	if(s2[i]=='1')
		var2++;

	vll v;
	ll lowe = abs(var1 - var2);
	ll uppe = var2+ var1;
	if(uppe>n)
		uppe = 2*n - var1 - var2;
	for(i=lowe;i<=uppe;i+=2)
		v.pb(i);
	ll sum = 0;
	for(auto u :v){
		//cout<<u<<khtm;
		sum = (sum+nCrModPFermat(n,u))%mod;
	}
	cout<<sum;

	cout<<khtm;

}


    return 0;

}