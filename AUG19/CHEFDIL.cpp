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

testcase{
    string s;
    cin>>s;
    i=0;
    ll cnt=0;
    k=s.length();
    fr(i,0,k){
        if(s[i]=='1')
            cnt++;
        

    }
    if(cnt%2)
        cout<<"WIN";
    else 
        cout<<"LOSE";
    cout<<khtm;
}

    return 0;
 
}