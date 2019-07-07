#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define maxi 30000005
#define PI 3.14159265358979323
#define debug(x) cout<<"Case "<<x<<": "
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long int           ll;
typedef long double             ld;
typedef unsigned long long int ull;
typedef vector <int>            vi;
typedef vector <ll>            vll;
typedef pair <int, int>        pii;
typedef pair <ll, ll>          pll;

//Handle:cyber_rajat

bool isPrime[maxi];

void SieveOfEra() 
{ 
	for(ll i=0;i<maxi;i++)
		isPrime[i]=true;

    for (ll i=2; i*i<=maxi; i++) 
    {  
       if (isPrime[i] == true) 
       {  
        	for (ll j=i*2; j<=maxi; j += i) 
               isPrime[j] = false; 
       } 
    } 
    isPrime[0]=false;
    isPrime[1]=false;
} 


int main(int argc, char const *argv[])
{
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	SieveOfEra();
	ll n;
	cin>>n;
	vector< pair<ll,ll> > pm,comp,result;
	ll x;
	ll total_sum=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		total_sum+=x;
		if(isPrime[x])
			pm.push_back(mp(x,i));
		else
			comp.push_back(mp(x,i));
	}

	ll flag=false;
	for(ll i=0;i<pm.size();i++)
	{
		for(ll j=0;j<comp.size();j++)
		{
			ll val=pm[i].first+comp[j].first;
			if(isPrime[val])
			{
				result.push_back(mp(pm[i].second,comp[j].second));
				pm.push_back(mp(val,comp[j].second));
				flag=true;
				comp.erase(comp.begin()+j);
				pm.erase(pm.begin()+i);
				break;
			}
			else if(isPrime[total_sum+comp[j].first]-pm[i].first)
			{
				result.push_back(mp(pm[i].second,comp[j].second));
				pm.push_back(mp(val,comp[j].second));
				flag=true;
				comp.erase(comp.begin()+j);
				pm.erase(pm.begin()+i);
				break;
			}
		}
		if(flag){
			i--;
			flag=false;
		}
	}
	
	if(pm.empty())
	{
		for(ll i=1;i<n;i++)
			cout<<i<<" "<<i+1<<endl;
		return 0;
	}

	if(comp.empty())
	{
		ll len=pm.size()-1;
		for(ll i=0;i<len;i++)
			result.push_back(mp(pm[i].second,pm[len].second));
	}

	for(ll i=0;i<result.size();i++)
	{
		cout<<result[i].first<<" "<<result[i].second<<endl;
	}

	return 0;
}
