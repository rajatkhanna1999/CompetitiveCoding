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

// Driver Code to test above function 
int main() 
{  
	ll n, k;
	cin >> n >> k;
	ll a[n+5];
	rep(i,n){
		cin >> a[i];
	}
	sort(a, a + n); 
	ll product = 1; 
	if (a[n - 1] == 0 && k%2 == 1){
		cout << 0 << endl;
		return 0; 
	}
	if (a[n - 1] <= 0 && k%2 == 1) { 
		for (ll i = n - 1; i >= n - k; i--) {
			product *= a[i]; 
			product += mod;
			product %= mod;
		}
		cout << (product+mod)%mod << endl;
		return 0; 
	} 
	ll i = 0; 
	ll j = n - 1; 
	if (k%2 == 1) { 
		product *= a[j]; 
		product += mod;
		product %= mod;
		j--; 
		k--; 
	} 
	k >>= 1;
	for (ll itr = 0; itr < k; itr++) { 

		ll left_product = a[i] * a[i + 1];
		ll right_product = a[j] * a[j - 1];

		if (left_product > right_product) { 
			left_product += mod; 
			left_product %= mod;
			product *= left_product; 
			product += mod;
			product %= mod;
			i += 2; 
		} 
		else { 
			right_product += mod;  
		    right_product %= mod;
			product *= right_product; 
			product += mod;
			product %= mod;
			j -= 2; 
		} 
	} 
	cout << (product+mod)%mod << endl;
	return 0; 
} 

