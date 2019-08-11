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
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	//#endif
	ll dp[8005]={0};
	dp[0]=1;
	ll possible_coins[]={1,5,10,25,50};
	for(ll i=0;i<5;i++)
	{
		for(ll j=possible_coins[i];j<8001;j++)
		{
			dp[j]=dp[j]+dp[j-possible_coins[i]];
		}
	}
	ll n;
	//cin>>n;
	while(scanf("%lld",&n)!=EOF)
		cout<<dp[n]<<endl;
	return 0;
}
