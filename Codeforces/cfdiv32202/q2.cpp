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
	ll n;
	cin>>n;
	ll sum=0;
	ll a[n+5]={0},even[n+5]={0},odd[n+5]={0};
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(i%2==0)
			even[i]=even[i-1]+a[i],odd[i]=odd[i-1];
		else
			odd[i]=odd[i-1]+a[i],even[i]=even[i-1];
	}
	ll cnt=0;
	for(ll i=1;i<=n;i++)
	{
		ll val1 = even[i-1]+odd[n]-odd[i];
		ll val2 = odd[i-1]+even[n]-even[i];
		if(val1==val2)
			cnt++; 
	}
	cout<<cnt<<endl;
	return 0;
}
