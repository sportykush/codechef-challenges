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
#define fr(i,a,n) for(i=a;i<n;i+=2)
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

//ll a[MAX];



int main()
{

  #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

fast

testcase{
    ll x,y;
    cin>>x>>y;
    cin>>n>>m>>k;
    ll yx;
    yx=2*(n+m);
    vpll A,B;
    ld ans = 0;
    int flag =0;
    ld temp1 = INT_MAX;
    ll x1,y1;
    fr(i,0,yx){
        ll a,b;
        cin>>a>>b;
        ld temp = (x-a)*(x-a) + (y-b)*(y-b);
        
        if(i<2*n){
            A.pb(a,b);
            if(temp<temp1)
            {
                x1 = a,y1=b;
                temp1 = temp;
                flag = 1;
            }
        }
        else{
            B.pb(a,b);
            if(temp<temp1)
            {
                x1 = a,y1=b;
                temp1 = temp;
                flag = 2;
            }

        }


    }
    cout<<temp1<<' '<<x1<<' '<<y1<< khtm;
    ans+=sqrt(temp1);
    ll x2,y2;
    
    if(flag == 1){
        temp1 = INT_MAX;
        for(auto u:B){
            ld temp = (x1 - u.F)*(x1 - u.F) + (y1 - u.S)*(y1 - u.S);
            if(temp<temp1){
                temp1 = temp;
                x2=u.F;
                y2= u.S;
            }
        } 
        ans+=sqrt(temp1);
        cout<<temp1<<' '<<x2<<' '<<y2<<khtm;
    }
    
    else if(flag == 2){
        temp1 = INT_MAX;
        for(auto u:A){
            ld temp = (x1 - u.F)*(x1 - u.F) + (y1 - u.S)*(y1 - u.S);
            if(temp<temp1){
                temp1 = temp;
                x2=u.F;
                y2= u.S;
            }
        } 
        ans+=sqrt(temp1);
        cout<<temp1<<' '<<x2<<' '<<y2<<khtm;
    }
    temp1 = INT_MAX;
    fr(i,0,2*k){
        ll a,b;
        cin>>a>>b;
        ld temp = (x2-a)*(x2-a) + (y2-b)*(y2-b);
        if(temp<temp1){
            temp1 = temp;
        }

    }

    ans+=sqrt(temp1);
    cout<<temp1<<khtm;
    cout<<setprecision(11) << ans;
    cout<<khtm;
    
}


    return 0;
}