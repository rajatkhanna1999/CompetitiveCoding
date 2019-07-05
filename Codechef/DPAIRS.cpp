#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define PI 3.14159265358979323
#define debug(x) cout<<"Case "<<x<<": "
#define For(i,n) for(long long i=0;i<n;i++)
#define Frabs(i,a,b) for(long long i = a; i < b; i++)
#define Frabr(i,a,b) for(long long i = a; i >=b; i--)
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

//Handle:cyber_rajat

int main(int argc, char const *argv[])
{
	sync;
	ll n,m;
	cin>>n>>m;
	pair<ll,ll > a[n+5],b[m+5];
	for(ll i=0;i<n;i++)
		cin>>a[i].first,a[i].second=i;
	for(ll i=0;i<m;i++)
		cin>>b[i].first,b[i].second=i;
	sort(a,a+n);
	sort(b,b+m);
	for(ll i=0;i<m;i++)
		cout<<a[n-1].second<<" "<<b[i].second<<endl;
	for(ll i=0;i<(n-1);i++)
		cout<<a[i].second<<" "<<b[0].second<<endl;
	 	
	return 0;
}
