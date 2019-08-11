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
//Did not understood much 

ll fiveortwos(ll x,ll v)
{
	ll cnt=0;
	while(x%v==0)
	{
		x=x/v;
		cnt++;
	}
	return cnt;
}

//Let dp[i][j][l] be the maximum amount 
//of twos we can collect by checking first i numbers, 
//taking j of them with total power of five equal to l. 

ll dp[2][205][5005];//dp[index][included][fives]=twos
bool visit[2][205][5005];
//Memory limit exceedes so use 2 length array
//fives=30 and totalfives=n*30=5000
//n=200
//two=63
//M2=63, M5 = 30;
ll M2=63,M5=30;

int main(int argc, char const *argv[])
{
	sync;
	ll pow2[M2],pow5[M5],two[205],five[205];
	//memset(pow5,1,sizeof(pow5));
	//memset(pow2,1,sizeof(pow2));
	pow2[0]=pow5[0]=1;
	for(ll i=1;i<M2;i++)
		pow2[i]=2*pow2[i-1];
	for(ll i=1;i<M5;i++)
		pow5[i]=5*pow5[i-1];
	ll n,k;
	cin>>n>>k;
	ll arr[205]={0};
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		for(ll j=0;j<M2;j++)
		{
			if(arr[i]>=pow2[j] && arr[i]%pow2[j]==0)
				two[i]=j;
		}
		for(ll j=0;j<M5;j++)
		{
			if(arr[i]>=pow5[j] && arr[i]%pow5[j]==0)
				five[i]=j;
		}
	}
	visit[0][0][0]=true;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<=k;j++)
		{
			for(ll q=0;q<=5001;q++)
			{
				if(visit[0][j][q])
				{
					visit[1][j][q]=visit[1][j+1][q+five[i]]=true;
					dp[1][j+1][q+five[i]]=max(dp[1][j+1][q+five[i]],dp[0][j][q]+two[i]);
					dp[1][j][q]=max(dp[1][j][q],dp[0][j][q]);
				}
			}
		}
		for(ll j=0;j<=k;j++)
		{
			for(ll q=0;q<=5001;q++)
			{
				dp[0][j][q]=dp[1][j][q];
            	dp[1][j][q]=0;
            	visit[0][j][q]=visit[1][j][q];
			}
		}
	}
    ll ans=0;
    for(ll i=0;i<5005;i++)
    	ans=max(ans,min(i,dp[0][k][i]));
    cout<<ans<<endl;
	return 0;
}
