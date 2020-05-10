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
#define bug(x)                            	cout << x << endl
#define ERASE(x)                          	x.erase(unique(x.begin(),x.end()),x.end())
#define pb                                	emplace_back
#define vii 					   		  	vector<int>
#define vll 							  	vector<ll>
#define vpll 								vector< pair <ll,ll> >
#define pll 								pair <ll,ll>
#define pii 								pair <int,int>
#define pq 									priority_queue< int >
#define khtm 								"\n"
#define F 									first
#define S 									second
#define fr(i,a,n) 							for(i=a;i<n;i++)
#define mem(arr,l) 							memset(arr,l,sizeof arr)
#define ALL(x) 								x.begin(), x.end()
#define frr(i,a,n) 							for(i=n-1;i>=a;i--)
#define mod 								1000000007
#define fast 								ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcase 							ll T; cin>>T; while(T--)
//////////////////////////////////////////////////////////////////////////////////////
const int MAX = 1e6 +2;
const int inf = (int) 1e9;
const int N = 1010;
const int maxe = 1e5 +5;


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
ll fac[maxe][N];
ll vis[MAX];
vll adj[MAX];


ll d[1002][1002];
map<ll,ll> mp[1002];

void primeFactors(ll pos,ll num)
{
    while (num % 2 == 0)
    {
        mp[pos][2]++;
        num = num/2;
    }
    for (int i = 3; i <= sqrt(num); i+=2)
    {
        while (num % i == 0)
        {
            mp[pos][i]++;
            num = num/i;
        }
    }
    if (num > 2)
        mp[pos][num]++;
}
void bfs(ll x)
{
    queue<ll> q;
    vis[x]=1;
    q.push(x);
    while(!q.empty())
    {
        ll c=q.front();
        q.pop();
        for(auto j:adj[c])
        {
            if(vis[j]==0)
            {
                mp[j]=mp[c];
                primeFactors(j,a[j]);
                ll kj=1;
                for(auto it:mp[j])
                {
                  kj = ((kj%mod)*((it.S+1)%mod))%mod;
                }
                d[x][j]=kj;
                q.push(j);
                vis[j]=1;
           }
    	}

	}
}

void ini(ll node)
{
	ll kr;
	fr(kr,0,1003)
	{
		vis[kr] = 0;
		mp[kr].clear();
	}
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
	fr(i,1,n+1)
	{
		adj[i].clear();
		vis[i] = 0;
	}
	fr(i,0,n-1)
	{
		cin >> l >> r;
		adj[l].pb(r);
		adj[r].pb(l);
	}
	ll mx = 0;
	fr(i,1,1+n){
		cin >> a[i];
		ini(i);
        primeFactors(i,a[i]);
        ll pro=1;
        for(auto it:mp[i])
        {
        	pro = ((pro%mod)*((it.S+1)%mod))%mod;
        }

             d[i][i]=pro;
           bfs(i);
	}

	ll q;
	cin >> q;
	while(q--)
	{
		ll u,v;
		cin >> u >> v;
		ll ans = d[u][v];
		cout << ans << khtm;
	}

}


  #ifndef ONLINE_JUDGE
  cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s";
  #endif
 
  return 0;
  
}