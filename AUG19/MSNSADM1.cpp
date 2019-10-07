#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define vpll vector< pair <ll,ll> >
#define pll pair <ll,ll>
#define pq priority_queue< int >
#define khtm "\n"
#define F first
#define S second
#define fr(i,a,n) for(i=a;i<n;i++)
#define frr(i,a,n) for(i=n;i>a;i--)
#define mod 998244353
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcase int T; cin>>T; while(T--)
 
 
/*Author-KUSHAGRA SINGH
Birla Institute of Technology
CS K18
*/
 

 ll i,j,n,m,k;

int main (){
 
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout);
#endif

fast

testcase{
    cin>>n;
    ll a[n],b[n];
    fr(i,0,n){
        cin>>a[i];
        a[i]*=20;
    }
    ll ans=0;

    fr(i,0,n){
        cin>>b[i];
        b[i]*=10;
        a[i]=a[i]-b[i];
        if(a[i]<0)
            a[i]=0;
        ans=max(ans,a[i]);
    }
    cout<<ans<<khtm;

   
}

    return 0;
 
}