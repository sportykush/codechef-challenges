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
 

 ll j,m,k;

int main (){
 
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout);
#endif

fast

testcase{
    int i,n;
    
   cin>>n;
    int c[n+1],a[n+1]={0},h[n+1];
fr(i,1,n+1) cin>>c[i];
fr(i,1,n+1) cin>>h[i];

fr(i,1,n+1){
     ll l=max(i-c[i],1);
     ll r=min(i+c[i],n);
     a[l]++;
     if(r==n)
      continue;
    
     
     a[r+1]--;
}

fr(i,0,n)
a[i+1]+=a[i];

   sort(a+1,a+n+1);

   sort(h+1,h+n+1);
   
   int flag=0;
   fr(i,1,n+1)
   if(a[i]==h[i])
    flag++;
if(flag==n)
    cout<<"YES";
else cout<<"NO";
        cout<<khtm;

}

    return 0;
 
}