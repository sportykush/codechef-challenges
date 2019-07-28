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
#define testase int T; cin>>T; while(T--)


/*Author-KUSHAGRA SINGH
Birla Institute of Technology
CS K18
*/
 
  ll i,j,n;

 
int main (){
/*
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    */

fast



testase{
cin>>n;
ll a[n+1],b[n+1];
fr(i,1,n+1){
cin>>b[i];
a[i]=b[i];}
a[0]=0;

fr(i,2,n+1){
    a[i]= max(a[i-2]+b[i-1]*i +b[i]*(i-1),a[i-1]+b[i]*i);
}

cout<<a[n];

cout<<khtm;
}
	return 0;
}



 