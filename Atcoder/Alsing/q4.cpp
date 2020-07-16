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
const int M = 200005;
ll dp1[M], dp2[M];
ll ans[M];

int main(int argc, char const *argv[])
{
	sync;
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll X = 0, N = 0;
	rep(i,n){
		if(s[i] == '1'){
			N++;
		}
	}
	mem(dp1, 0);
	mem(dp2, 0);
	mem(ans, -1);
	dp2[n-1] = 1;
	if((N-1) >= 1){
		dp1[n-1] = 1;
		for(int i = n-2; i >= 0; i--){
			dp1[i] = (2*dp1[i+1])%(N-1);
		}
	}
	for(int i = n-2; i >= 0; i--){
		dp2[i] = (2*dp2[i+1])%(N+1);
	}
	ll sum1 = 0, sum2 = 0;
	for(int i = n-1; i >= 0; i--){
		if((N-1) >= 1){
			if(s[i] == '1'){
				sum1 += dp1[i];
				sum1 %= (N-1);
			}
		}
		if(s[i] == '1'){
			sum2 += dp2[i];
			sum2 %= (N+1);
		}
	}
	rep(i,n){
		if(s[i] == '1'){
			X += (1LL<<(n-1-i));
		}
	}
	//cout << N sp sum1 sp sum2 sp X sp X%(N-1) sp X%(N+1)<< endl;
	vector<ll> v;
	for(int i = 0; i < n; i++){
		ll val;
		if(s[i] == '0'){
			val = (sum2 + dp2[i])%(N+1);
		}else{
			val = 0;
			if(N == 1){
				ans[i] = 0;
			}
			if((N-1) >= 1){
				val = (sum1 - dp1[i] + N - 1)%(N-1);
			}
		}
		v.push_back(val);
	}
	for(int i = 0; i < n; i++){
		if(ans[i] == -1){
			ans[i] = 1;
		}
		ll val = v[i];
		ll cnt = 0;
		while(val > 0){
			val %= (__builtin_popcount(val));
			cnt++;
		}
		ans[i] += cnt;
	}
	// rep(i,n){
	// 	ll val = X;
	// 	if(s[i] == '1'){
	// 		val -= (1LL<<(n-1-i));
	// 	}else{
	// 		val += (1LL<<(n-1-i));
	// 	}
	// 	val %= (__builtin_popcount(val));
	// 	cout << v[i] sp val << endl;
	// }
	rep(i,n){
		cout << ans[i] << endl;
	}
	return 0;
}
