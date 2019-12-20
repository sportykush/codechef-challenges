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



int main()
{

  #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

fast

testcase{
	cin>>n;
	string s;
    cin>>s;
    //cout<<LRSLength(s,n,n);
    vll v[26];
    fr(i,0,n)
    {
        ll temp = s[i] - 'a';
        v[temp].pb(i);
    }
    int flag = 0;
    ll ans = MAX;
    fr(i,0,26){
        if(v[i].size()>1)
        {
            flag = 1;
            ll mx= MAX;
            fr(j,0,v[i].size()-1)
            {
                mx= min(v[i][j+1]-v[i][j],mx);
            }
            ans = min(ans,mx);

        }
    }

    if(!flag)
        cout<<0;
    else
        cout<<n-ans;


	cout<<khtm;

}


    return 0;

}