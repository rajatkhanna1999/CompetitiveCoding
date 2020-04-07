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
	ll arr[n*n+5]={0},freq[1005]={0};
	vector<ll> v,v1,v2;
	set<ll> s;
	ll output[n+2][n+2]={0};
	for(ll i=0;i<n*n;i++)
		cin>>arr[i],freq[arr[i]]++,s.insert(arr[i]);
	if(n%2==0)
	{
		set<ll>::iterator it;
		for(it=s.begin();it!=s.end();it++)
		{
			if(freq[*it]%4==0)
				v.push_back(*it);
			else
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		ll r=0,c=-1;
		for(ll i=0;i<v.size();i++)
		{
			label:;
			c++;
			if(c==(n/2))
				r++,c=0;
			//cout<<v[i]<<" "<<freq[v[i]]<<" "<<r<<" "<<c<<" "<<i<<endl;
			ll quantity=freq[v[i]];
			output[r][c]=v[i];
			output[n-1-r][c]=v[i];
			output[r][n-1-c]=v[i];
			output[n-1-r][n-1-c]=v[i];
			freq[v[i]]=freq[v[i]]-4;
			if(freq[v[i]]>0)
				goto label;
		}
	}
	else
	{
		set<ll>::iterator it;
		for(it=s.begin();it!=s.end();it++)
			if(freq[*it]%4==0)
				v.push_back(*it);
			else
			{
				if(freq[*it]%4==1)
				    v1.push_back(*it);
				else if(freq[*it]%4==2)
					v2.push_back(*it);
			    else{
			    	cout<<"NO"<<endl;
			    	return 0;
			    }
			}
		if(v1.size()>1){
			cout<<"NO"<<endl;
			return 0;
		}
		output[(n/2)][(n/2)]=v1[0];
		freq[v1[0]]--;
		ll r1=0,c1=n/2;
		/*for(ll i=0;i<v2.size();i++)
		{
			if(r1==(n/2))
				r1=n/2;
			output[r1][c1]=v2[i];
			output[n-1-r1][c1]=v2[i];
			r1++;
		}*/
		ll r=0,c=-1;
		for(ll i=0;i<v.size();i++)
		{
			label1:;
			c++;
			if(c==((n/2)+1))
				r++,c=0;
			//cout<<v[i]<<" "<<freq[v[i]]<<" "<<r<<" "<<c<<" "<<i<<endl;
			ll quantity=freq[v[i]];
			output[r][c]=v[i];
			output[n-1-r][c]=v[i];
			output[r][n-1-c]=v[i];
			output[n-1-r][n-1-c]=v[i];
			freq[v[i]]=freq[v[i]]-4;
			if(freq[v[i]]>0)
				goto label1;
		}
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				if(output[i][j]==0)
					output[i][j]=v1[0];
			}
		}
	}
	cout<<"YES"<<endl;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			cout<<output[i][j]<<" ";
		}
		cout<<endl;
	}		
	return 0;
}
