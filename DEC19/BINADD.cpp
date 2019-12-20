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


// ll a[MAX],b[MAX];




int main()
{

  #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

fast

testcase{
	string s1,s2;

	cin>>s1>>s2;
	n = max(s1.size() , s2.size());
	int a[n] ={0}, b[n]={0};
	j=n-1;
	for(i=s1.size()-1;i>=0;i--)
	{
		a[j] = s1[i]-'0';
		j--;
	}

		j=n-1;
	for(i=s2.size()-1;i>=0;i--)
	{
		b[j] = s2[i]-'0';
		j--;
	}

	if(s2[0] == '0')
	{
		cout<<0;
	}

	else{
		ll ans = 0;
		for(i=n-1;i>=0;i--){
			ll mx= 0;
			if(a[i]==1 && b[i] == 1)
			{
				
				i--;
				mx++;
				while(a[i]!=b[i] && i>=0){
					i--;
					mx++;
					//cout<<mx<<khtm;
				}
				i++;
				ans = max(ans,mx);
			}
		}
		//cout<<khtm;
		cout<<ans+1;
		//cout<<khtm;
	}
	cout<<khtm;

}


    return 0;

}