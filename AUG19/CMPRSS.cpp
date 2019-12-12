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

ll a[MAX];

int main()
{

  #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output_2.txt", "w", stdout);
#endif

fast
testcase{
	cin>>n;
	j = 0;
	cin>>a[0];
	int cnt = 0;
	if(n==1) cout<<a[0];
	fr(i,1,n){
		cin>>a[i];
		if(a[i] == a[i-1] + 1)
		{
			if(cnt == 0)
				j = i-1;
			cnt++;
		}
		if((a[i] == a[i-1] + 1 ) &&  (i==n-1) && cnt<2)
			cout<<a[i-1]<<','<<a[i];
		if(a[i] != a[i-1] + 1){
			if(cnt == 0)
				cout<<a[i-1]<<',';
			else if(cnt == 1)
				cout<<a[j]<<','<<a[i-1]<<',';
			else
				cout<<a[j]<<"..."<<a[i-1]<<',';
			cnt = 0;
		}
		if((a[i] != a[i-1] + 1 ) &&  (i==n-1))
			cout<<a[n-1];
		if((a[i] == a[i-1] + 1 ) &&  (i==n-1) && cnt>1)
			cout<<a[j]<<"..."<<a[i];
	}


	cout<<khtm;
	
}

	return 0;
}