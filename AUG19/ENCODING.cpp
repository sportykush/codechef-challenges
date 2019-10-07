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
#define frr(i,a,n) for(i=n-1;i>=a;i--)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcase int T; cin>>T; while(T--)
const int MAX =1e5 + 2;
const int mod = 1e9 + 7;
 
 
/*Author-KUSHAGRA SINGH
Birla Institute of Technology
CS K18
*/
 
vector <int> v(MAX);

ll i,j,n,m,k;

ll solve(string s, bool inc) {
    v[0] = 0;
    fr(i,1,1+s.size()) 
        v[i] = (10LL * v[i - 1] + s[i - 1] - '0') % mod;
    
    ll pow = 1, sum = 0, low = 0;
    frr (i,1,s.size()) {
        ll pow2 = pow * pow % mod;
        sum += 45LL * v[i - 1] % mod * pow2;
        sum %= mod;
        sum += (s[i - 1] - '0') * (s[i - 1] - '0' - 1) / 2LL * pow2;
        sum %= mod;
        if (s[i] == s[i - 1]) {
            sum += (ll) (low + inc) * (s[i - 1] - '0') % mod * pow;
            sum %= mod;
        }

        else if (s[i - 1] < s[i]) {
            sum += (ll) (s[i - 1] - '0') * pow2;
            sum %= mod;
        }
        low += (s[i] - '0') * pow;
        low %= mod;
        pow *= 10;
        pow %= mod;
    }
    return ((ll) v[s.size()] * (v[s.size()] + (2 * inc - 1)) / 2 - sum) % mod;
}

int main (){
 
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout);
#endif

fast

testcase{
    ll nl, nr;
    string l, r; 
    cin >> nl >> l >> nr >> r;
    ll ans = (solve(r, 1) - solve(l, 0)) % mod;
    cout << (ans >= 0 ? ans : ans + mod) << khtm;
}
	
    return 0;
 
}