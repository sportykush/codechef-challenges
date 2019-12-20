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


ll i,j,l,m,r;

ll a[MAX];


ll solve(ll y, ll b){
   int k=0;
    for(i=1;i*i<=b;i++)
        if(b%i == 0)
            a[k++] = i;
        ll ans = 2*(y+b) + 2;
        ll x= y+b;
       int n= 0;
        for (i = 1; i * i <= x; ++i){
        if (x % i == 0){
            while (n + 1 < k && a[n + 1] <= i)
                ++n;
            if (b / a[n] <= x / i)
                ans = min(ans, (i + x / i) * 2);
        }
    }
    
    return ans;
}



int main()
{

  #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

fast


cin>>l>>r;
cout<<min(solve(l,r) , solve(r,l));


    return 0;
}