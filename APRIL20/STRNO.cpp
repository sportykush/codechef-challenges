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
 ll vis[MAX];
int main()
{
 
  #ifndef ONLINE_JUDGE
freopen("input_1.txt", "r", stdin);
freopen("output_1.txt", "w", stdout);
#endif
//cout << setprecision(15) << fixed;
fast

// vll v;
// fr(i,2,MAX)
// {
//   if(vis[i]==0)
//   {
//     v.pb(i);
//     for(j = 2*i ; j<MAX ; j += i)
//       vis[j] = 1;
//   }
// }
//cout << v.size();
testcase
{
  ll x;
  cin >> x >> k;
  if(k == 1)
  {
    if(x > 1)
      cout << "1\n";
    else
      cout << "0\n";
  }

  else
  {
    ll tm = pow(2,k);
    if(x >= tm){
      ll tr = 0;
      while(x%2 == 0)
      {
        tr++;
        x/=2;
      }
      for(i = 3 ; i*i <= x; i+=2)
      {
        cout << 'x';
        while(x%i == 0)
        {
          tr++;
          x/=i;
        }
      }
      if(x > 2)
        tr++;
      //cout << tr;
      if(tr>=k)
        cout << "1\n";
      else
        cout << "0\n";
    }

    else
    {
      cout << "0\n"; 
    }

    
  }
}


  #ifndef ONLINE_JUDGE
  cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s";
  #endif
 
  return 0;
 
}