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
  vll v;
  fr(i,0,n){
   cin >> a[i];
   if(a[i] == 1)
    v.pb(i+1);
  }
  m = v.size();
  if(m == 1)
    cout << "YES\n";
  else
  {
    ll f = 0;
    fr(i,1,m)
    {
      if(v[i]-v[i-1] <6){
        f = 1;
        break;
      }
    }
    if(f)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  //cout << "\n";
}


  #ifndef ONLINE_JUDGE
  cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s";
  #endif
 
  return 0;
 
}