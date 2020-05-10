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
//#define mod1 998244353 
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcase ll T; cin>>T; while(T--)
const int MAX = 1e6 +2;
const ll M = 998244353;
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
 
ll gcd(ll a, ll b)
{
  if (a == 0) 
        return b; 
    return gcd(b%a, a);
}
  
// To compute x raised to power y under modulo m 
ll power(ll x,  ll y,  ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
  
// Function to find modular inverse of a under modulo m 
ll modInverse(ll a, ll m) 
{ 
    ll g = gcd(a, m); 
  return power(a, m-2, m); 
    
} 
  
// To compute x^y under modulo m 
vpll array1[4],array2[4],array3[4];
ll probablity[4];
ll result1,result2,result3,result4;
ll expcalc(char ch){
    if(ch == '&'||ch == '^'||ch=='|')
        return 1;
    return 0;
}
ll k1[4],k2[4];


ll finde(vll g, vll u, char ch, ll j){
    ll ans=0;
    if(ch=='|')
    {
        for(ll i=0;i<array1[j].size();i++)
        {
            ans=(ans+(g[array1[j][i].first]*u[array1[j][i].second])%M)%M;
        }
        return ans;
    }
    if(ch=='&')
    {
        for(ll i=0;i<array2[j].size();i++)
        {
            ans=(ans+(g[array2[j][i].first]*u[array2[j][i].second])%M)%M;
        }
        return ans;
    }
    if(ch=='^')
    {
        for(ll i=0;i<array3[j].size();i++)
        {
            ans=(ans+(g[array3[j][i].first]*u[array3[j][i].second])%M)%M;
        }
        return ans;
    }
}


void calculate(string str){
    stack <ll> value[4];
    stack <char> newst;
    ll i;
    fr(i,0,str.length()){

        if(str[i] == ' ')
            continue;

        else if(str[i] == '('){
            newst.push(str[i]);
        }

        else if(str[i]=='#'){
            ll val = probablity[0];
            value[0].push(val);
            value[1].push(val);
            value[2].push(val);
            value[3].push(val);
        }


        else if(str[i] == ')')
        {
            while(!newst.empty() && newst.top() != '(')
            {
                vll val2,val1;
                val2.clear();
                val1.clear();
                val2.pb(value[0].top());
                value[0].pop();
                val2.pb(value[1].top());
                value[1].pop();
                val2.pb(value[2].top());
                value[2].pop();
                val2.pb(value[3].top());
                value[3].pop();

                val1.pb(value[0].top());
                value[0].pop();
                val1.pb(value[1].top());
                value[1].pop();
                val1.pb(value[2].top());
                value[2].pop();
                val1.pb(value[3].top());
                value[3].pop();

                char op = newst.top();
                newst.pop();

                value[0].push(finde(val1,val2, op,0));
                value[1].push(finde(val1,val2, op,1));
                value[2].push(finde(val1,val2, op,2));
                value[3].push(finde(val1,val2, op,3));

            }


            if(!newst.empty())
               newst.pop();
        }


        else
        {

            while(!newst.empty() && expcalc(newst.top()) >= expcalc(str[i]))
            {
                vll val2,val1;
                val2.clear();
                val1.clear();
                val2.pb(value[0].top());
                value[0].pop();
                val2.pb(value[1].top());
                value[1].pop();
                val2.pb(value[2].top());
                value[2].pop();
                val2.pb(value[3].top());
                value[3].pop();

                val1.pb(value[0].top());
                value[0].pop();
                val1.pb(value[1].top());
                value[1].pop();
                val1.pb(value[2].top());
                value[2].pop();
                val1.pb(value[3].top());
                value[3].pop();

                char op = newst.top();
                newst.pop();

                value[0].push(finde(val1,val2, op,0));
                value[1].push(finde(val1,val2, op,1));
                value[2].push(finde(val1,val2, op,2));
                value[3].push(finde(val1,val2, op,3));
            }


            newst.push(str[i]);
        }
    }


    while(!newst.empty()){
        vll val2,val1;
                val2.clear();
                val1.clear();
                val2.pb(value[0].top());
                value[0].pop();
                val2.pb(value[1].top());
                value[1].pop();
                val2.pb(value[2].top());
                value[2].pop();
                val2.pb(value[3].top());
                value[3].pop();

                val1.pb(value[0].top());
                value[0].pop();
                val1.pb(value[1].top());
                value[1].pop();
                val1.pb(value[2].top());
                value[2].pop();
                val1.pb(value[3].top());
                value[3].pop();

                char op = newst.top();
                newst.pop();

                value[0].push(finde(val1,val2, op,0));
                value[1].push(finde(val1,val2, op,1));
                value[2].push(finde(val1,val2, op,2));
                value[3].push(finde(val1,val2, op,3));
    }

    result1= value[0].top();
    result2= value[1].top();
    result3= value[2].top();
    result4= value[3].top();
}

int main()
{

 

  #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
//cout << setprecision(15) << fixed;
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    //function1();
    array1[0].pb(0,0);
    array1[1].pb(0,1);
    array1[1].pb(1,0);
    array1[1].pb(1,1);
    array1[1].pb(1,2);
    array1[1].pb(1,3);
    array1[1].pb(2,1);
    array1[1].pb(2,3);
    array1[1].pb(3,1);
    array1[1].pb(3,2);
    array1[2].pb(0,2);
    array1[2].pb(2,0);
    array1[2].pb(2,2);
    array1[3].pb(0,3);
    array1[3].pb(3,0);
    array1[3].pb(3,3);
    array2[0].pb(0,0);
    array2[0].pb(0,1);
    array2[0].pb(0,2);
    array2[0].pb(0,3);
    array2[0].pb(1,0);
    array2[0].pb(2,0);
    array2[0].pb(3,0);
    array2[0].pb(2,3);
    array2[0].pb(3,2);
    array2[1].pb(1,1);
    array2[2].pb(1,2);
    array2[2].pb(2,1);
    array2[2].pb(2,2);
    array2[3].pb(1,3);
    array2[3].pb(3,1);
    array2[3].pb(3,3);
    array3[0].pb(0,0);
    array3[0].pb(1,1);
    array3[0].pb(2,2);
    array3[0].pb(3,3);
    array3[1].pb(0,1);
    array3[1].pb(1,0);
    array3[1].pb(2,3);
    array3[1].pb(3,2);
    array3[2].pb(0,2);
    array3[2].pb(1,3);
    array3[2].pb(2,0);
    array3[2].pb(3,1);
    array3[3].pb(0,3);
    array3[3].pb(1,2);
    array3[3].pb(2,1);
    array3[3].pb(3,0);
    probablity[0]=(1*modInverse(4,M))%M;
    probablity[1]=(1*modInverse(4,M))%M;
    probablity[2]=(1*modInverse(4,M))%M;
    probablity[3]=(1*modInverse(4,M))%M;
testcase
    {
        string s;
        cin>>s;
        //s=#
        if(s.size()==1)
        {
                result1=probablity[0];
                result2=probablity[1];
                result3=probablity[2];
                result4=probablity[3];
        }
        else
        {
              calculate(s);
        }

        cout<<result1<<" "<<result2<<" "<<result3<<" "<<result4<<khtm;
}

  #ifndef ONLINE_JUDGE
  cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s";
  #endif

    return 0;
}