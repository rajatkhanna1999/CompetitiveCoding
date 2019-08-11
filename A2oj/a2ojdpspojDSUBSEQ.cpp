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
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll dp[100005];
		dp[0]=1;
		ll last[100];
		memset(last,-1,sizeof(last));
		for(ll i=0;i<s.size();i++)
		{
			dp[i+1]=dp[i]<<1;
			if(dp[i+1]>0)
				dp[i+1]=dp[i+1]%mod;
			else
				dp[i+1]=(dp[i+1]+mod)%mod;

			if(last[s[i]-'A']!=-1)
			{
				dp[i+1]=dp[i+1]-dp[last[s[i]-'A']-1];
				if(dp[i+1]>0)
					dp[i+1]=dp[i+1]%mod;
				else
					dp[i+1]=(dp[i+1]+mod)%mod;
			}
			last[s[i]-'A'] = i+1;
		}
		cout<<dp[s.size()]<<endl;
	}
	return 0;
}
