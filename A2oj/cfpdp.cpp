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
	ll n,k;
	cin>>n>>k;
	ll a[100005],b[100005];
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	for(ll i=1;i<=n;i++)
		cin>>b[i];
	ll sum=0;

	//1st approach
	//for(ll i=1;i<=n;i++)
	//{
	//	if(b[i])
	//		sum+=a[i],a[i]=0;
	//}
	// for(ll i=1;i<=k;i++)
	// 	sum+=a[i];
	// ll maxi=sum;
	// for(ll i=1,j=k+1;j<=n;i++,j++)
	// {
	// 	sum-=a[i];
	// 	sum+=a[j];
	// 	maxi=max(sum,maxi);
	// }
	// cout<<maxi<<endl;

	//2nd approach
	ll pr[n+5]={0};
	for(ll i=1;i<=n;i++)
	{
		pr[i]+=pr[i-1];
		if(b[i])
			sum+=a[i];
		else
			pr[i]+=a[i];
	}
	ll val=0;
	for(ll i=k;i<=n;i++)
	{
		val=max(val,pr[i]-pr[i-k]);
	}
	cout<<sum+val<<endl;
	return 0;
}
