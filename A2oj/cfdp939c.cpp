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
	ll arr[2*n+5]={0};
	for(ll i=0;i<n;i++)
		cin>>arr[i],arr[i+n]=arr[i];
	ll s,f;
	cin>>s>>f;
	ll interval=f-s;
	ll pre[2*n+5]={0};
	pre[0]=arr[0];
	for(ll i=1;i<2*n;i++)
		pre[i]=pre[i-1]+arr[i];
	ll tZone1=s,currtZone=0;
	ll maxAns=0,currentAns=0,j=1;
	maxAns=pre[interval-1];
	for(ll i=interval;i<2*n;i++)
	{
		currentAns=pre[i]-pre[i-interval];
		currtZone=s-j;
		while(currtZone<=0)
			currtZone=n+currtZone;
		if(currentAns>maxAns || (currentAns==maxAns && currtZone<tZone1))
			maxAns=currentAns,tZone1=currtZone;
		//cout<<currtZone<<" "<<tZone1<<" "<<maxAns<<" "<<currentAns<<" "<<i<<" "<<j<<endl;
		j++;
	}
	cout<<tZone1<<endl;
	return 0;
}
