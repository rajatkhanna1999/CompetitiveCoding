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

int main(int argc, char const *argv[])
{
	sync;
	ll n;
	cin >> n;
	ll a[n+5];
	ll XoR = 0, Sum = 0, And = 0;
	rep(i,n){
		cin >> a[i];
		XoR ^= a[i];
	}
	if(XoR == 0){
		cout << "0" << endl;
		return 0;
	}
	XoR ^= (a[0]^a[1]);
	Sum = a[0] + a[1];
	//XoR is required Xor and And is req and
	//A = a[0] - x, B = a[1] + x;
	//A^B = Xor
	//A + B = a[0] - x + a[1] + x = a[0] + a[1] = sum
	//A + B = A^B + 2(A&B)
	//Sum = XoR + 2*And
	if(XoR > Sum || (Sum - XoR)%2 != 0){
		cout << "-1" << endl;
		return 0;
	}

	And = (Sum - XoR)/2;

	//XoR and And will have no 1 bit same
	//and Thus there and must be zero
	//0,0 -> 0, 0
	//0,1 -> 0, 1
	//1,0 -> 0, 1
	//1,1 -> 1, 0
	if((And&XoR) != 0){
		cout << "-1" << endl;
		return 0;
	}

	if(And > a[0]){
		cout << "-1" << endl;
		return 0;
	}

	ll A = 0, B = 0;
	for(int i = 45; i >= 0; i--){
		if((XoR&(1LL<<i)) != 0){
			ll temp = B + (1LL<<i);
			if((temp^And) <= a[0]){
				B += (1LL<i);
			}
		}
	}
	A = B ^ And;
	if(A == 0){
		cout << "-1" << endl;
		return 0;
	}else{
		cout << a[0] - A << endl; 
	}
	return 0;
}
