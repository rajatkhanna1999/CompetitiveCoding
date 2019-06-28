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
ll ans[3005][3005];
ll tempans[3005][3005];
ll maxtempans[3005][3005];

int main(int argc, char const *argv[])
{
	sync;
	ll n;
	cin>>n;
	pair<ll,ll> arr[200005];
	for(ll i=1;i<=n;i++)
		cin>>arr[i].first>>arr[i].second;
	memset(ans,0,sizeof(ans));
	memset(tempans,0,sizeof(tempans));
	memset(maxtempans,0,sizeof(maxtempans));

	for(ll i=1;i<=n;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			tempans[i][j]=pow(arr[i].first-arr[j].first,2)+pow(arr[i].second-arr[j].second,2);
		}
	}
	for(ll j=1;j<=n;j++)
	{
		maxtempans[j][j]=0;
		for(ll i=j-1;i>=1;i--)
		{
			maxtempans[i][j]=max(tempans[i][j],maxtempans[i+1][j]);
		}
	}
	for(ll f=1;f<=n;f++)
	{
		for(ll t=f+1;t<=n;t++)
		{
			ans[f][t]=max(ans[f][t-1],maxtempans[f][t]);
		}
	}
	/*for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}*/
	ll q;
	cin>>q;
	while(q--)
	{
		ll f,t;
		cin>>f>>t;
		cout<<ans[f][t]<<endl;
	}
	
	return 0;
}
