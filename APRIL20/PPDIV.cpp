/*
auth - @sportykush
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; 
 
//#define mp make_pair
#define bug(x) cout << x << endl
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define pb emplace_back
#define vii vector<int>
#define vll vector<ll>
#define vpll vector< pair <ll,ll> >
#define pll pair <ll,ll>
#define pii pair <int,int>
#define pq priority_queue< int >
#define khtm "\n"
#define F first
#define S second
#define fr(i,a,n) for(i=a;i<n;i++)
#define mem(arr,l) memset(arr,l,sizeof arr)
#define ALL(x) x.begin(), x.end()
#define frr(i,a,n) for(i=n-1;i>=a;i--)
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcase ll T; cin>>T; while(T--)
const int MAX = 1e6 +2;
const int inf = (int) 1e9;
const int N = 1010;
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
ll find(ll n)
{
	//ll ans = 1;
	if(n<3)
		return 1;
	
	ll ui = 1;
		int tmp = 3;
		int it = 4;
		while(it<=n)
		{
			// m = 
			k = sqrt(it);
			ll num = it;
			if(n%it == 0)
			{
				while(n%num == 0)
				{
					ui+=num;
					//cout << num << 'x';
					num*=k;
					ll tmr = sqrt(num);
					if(tmr*tmr == num)
						num*=k;
				}
			}
			tmp+=2;
			it+=tmp;

		}
		return ui;
	
}
int main()
{
 
  #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
//cout << setprecision(15) << fixed;
fast

testcase
{
	cin >> n;
	ll ans;
	if(n < 4)
		ans = n;
	else
	{
		ans = 0;
		fr(i,1,n+1)
		{
			//cout << i << ' ';
			ans+=find(i);
			//cout << find(i) << khtm;


		}

	}
	cout <<  ans << khtm;
	
	
}


  #ifndef ONLINE_JUDGE
  cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s";
  #endif
 
  return 0;
 
}