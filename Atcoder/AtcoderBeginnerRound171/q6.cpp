#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
using namespace std;
using namespace __gnu_pbds;

#define sp << " " <<
#define mod 1000000007
#define MOD 1000000007
#define PI 3.14159265358979323
#define y second
#define x first
#define pb push_back
#define mp make_pair
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define pqueue priority_queue< ll >
//#define pdqueue priority_queue< ll,vector<ll> ,greater< ll > >
#define codejamDebug(x) cout<<"Case #"<<x<<": ";
#define debug(x) cout<<#x<<" :"<<x<<endl;
#define rep(i,n) for(long long i=0;i<n;i++)
#define f(i,a,b) for(long long i = a; i < b; i++)
#define fd(i,a,b) for(long long i = a; i >=b; i--)
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long int           ll;
typedef long double             ld;
typedef unsigned long long int ull;
typedef vector <int>            vi;
typedef vector <ll>            vll;
typedef pair <int, int>        pii;
typedef pair <ll, ll>          pll;
typedef vector < pii >        vpii;
typedef vector < pll >        vpll;
typedef vector <string>         vs;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Handle:cyber_rajat
const ll N = 2000005;
ll fact[N], invfact[N];

ll pow(ll a, ll b, ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

ll modinv(ll k)
{
	return pow(k, MOD-2, MOD);
}

void precompute()
{
	fact[0]=fact[1]=1;
	for(ll i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(ll i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}

ll nCr(ll x, ll y)
{
	if(y>x)
		return 0;
	ll num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}

int main(int argc, char const *argv[])
{
	sync;
	precompute();
	ll k;
	cin >> k;
	string s;
	cin >> s;
	ll n = s.size();
	//I was Using Multinomial Theorem but there are repetitions in it
	//http://www.quizsolver.com/blog/view/details/IIT-JEE/Multinomial-Theorem-and-Its-Applications-for-IIT-and-Other-Engineering-Exams/239/
	// ll val = nCr(n+k,k);
	// cout << val << endl;

	//Now to avoid repetitions we do the following:
	//The final length of sequence will be n + k
	//We will find the postion of where to place the last character of the given input string
	//it can be placed at [n,n+k]
	//at all positions before this character id placed, there can't be repiting elements
	//So for all postions unfilled before this we have 25 options
	//But after position of this character we can place any char from last postion to n+k
	//Now for placing nth character of string at ith postion, we will have to find number of ways
	//to do so
	//nCr : (i - 1, n - 1)
	ll ans = 0;  
	for(int len = n; len <= n + k; len++){
		ll curr = pow(26, n + k - len, MOD)*pow(25, len - n, MOD);
		curr %= MOD;
		curr *= nCr(len-1, n-1);
		curr %= MOD;
		ans += curr;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
