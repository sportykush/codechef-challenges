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
#define MAXN 1e8
 
/*Author-KUSHAGRA SINGH
Birla Institute of Technology
CS K18
*/

 
  

int main (){
 
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout);
#endif

fast
testcase{
	ll i,n,j,k;
    cin>>n;
    vector< pair < int , int > > v(n);
    vector < int >  kyu(n);
    cin>>k;
    
    kyu[0]=k;
    v[0].F=k;
    v[0].S=0;
     fr(i,1,n){
     	ll newtemp;
        cin>>newtemp;
        v[i].F=v[i-1].F^newtemp;
        kyu[i]=v[i].F;
        v[i].S=i;
    }
    

    ll ans=0;
    sort(v.begin(),v.end());
    sort(kyu.begin(),kyu.end());

    fr(i,0,n)
    {
    	if(v[i].F==0)
    	ans+=v[i].S;
    	else break;
    }
       ll m,cerr=0,res,ab=1;
       vector<int> :: iterator it;
    for(i=n-1;i>0;i--){
    	if(v[i].F == v[i-1].F){
    		m=v[i].F;
    		it=lower_bound(kyu.begin(),kyu.end(),m);
    		cerr=it-kyu.begin();
    		res=i-cerr;
    		for( j= cerr;j<i;j++)
    		{
    			ans+=res*ab*(v[j+1].S-v[j].S);
    			res--;
    			ab++;
    		}
    		ab=1;
    		ans-=((i-cerr+1)*(i-cerr))/2;
    		i=cerr;
    	}
    }

    /*

    fr(i,0,n+1){
        fr(j,i+1,n+1)
        if(b[i]==b[j])
        
            flag+=j-i-1;

    }
*/
  
cout<<ans;

        cout<<khtm;
}
    return 0;
 
}