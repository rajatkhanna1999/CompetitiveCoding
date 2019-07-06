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
vector<ll> a,b;
bool visited2[10005]={0};
vector<ll> arr[10005];

void dfs(ll flag,ll val)
{
	ll temp=1;
	visited2[val]=true;
	for(ll i=0;i<arr[val].size();i++)
	{
		if(!visited2[arr[val][i]] && !temp)
		{
			if(a.size()>b.size())
				b.push_back(arr[val][i]),dfs(1,arr[val][i]);
			else
				a.push_back(arr[val][i]),dfs(0,arr[val][i]);

		}
		else if(!visited2[arr[val][i]] && temp)
		{
			if(flag)
				a.push_back(arr[val][i]),temp=0;
			else
				b.push_back(arr[val][i]),temp=0;
			dfs(flag^1,arr[val][i]);
		}
		else
			continue;
	}
}

int main(int argc, char const *argv[])
{
	sync;
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		memset(arr,0,sizeof(arr));
		a.clear(),b.clear();
		bool visited[10005]={0};
		bool visited1[10005]={0};
		ll sizes[10005]={0};
		for(ll i=1;i<n;i++)
		{
			ll a,b;
			cin>>a>>b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		for(ll i=1;i<=n;i++)
			sizes[i]=arr[i].size();
		queue<ll> q;
		q.push(1);
		visited[1]=true;
		vector<ll> v;
		while(!q.empty())
		{	
			ll curr=q.front();
			v.push_back(curr);
			q.pop();
			for(ll j=0;j<arr[curr].size();j++)
			{
				if(!visited[arr[curr][j]])
				{
					visited[arr[curr][j]]=true;
					q.push(arr[curr][j]);
				}
			}
		}
		ll temp=0,count=0;
		ll tempcount=1;
		ll iterations=0;
		for(ll i=0;i<v.size();i++)
		{
			if(iterations==tempcount)
			{
				iterations=0;
				tempcount=count;
				temp=temp^1;
				count=0;
			}
			if(temp==0){
				a.push_back(v[i]);
				visited1[v[i]]=true;
				ll c2=0;
				for(ll j=0;j<arr[v[i]].size();j++)
				{
				    if(!visited1[arr[v[i]][j]])
				    c2++;
				}
				count=count+c2;
			}
			else{
				b.push_back(v[i]);
				visited1[v[i]]=true;
				ll c2=0;
				for(ll j=0;j<arr[v[i]].size();j++)
				{
				    if(!visited1[arr[v[i]][j]])
				    c2++;
				}
				count=count+c2;
			}
			iterations++;
		}
		if(a.size()==b.size())
		{
			cout<<"1"<<endl;
			for(ll i=0;i<a.size();i++)
				cout<<a[i]<<" ";
			cout<<endl;
			for(ll i=0;i<b.size();i++)
				cout<<b[i]<<" ";
			cout<<endl;
		}
		else
		{
			cout<<"2"<<endl;
			a.clear(),b.clear();
			a.push_back(1);
			memset(visited2,0,sizeof(visited2));
			dfs(0,1);
			for(ll i=0;i<a.size();i++)
				cout<<a[i]<<" ";
			cout<<endl;
			for(ll i=0;i<b.size();i++)
				cout<<b[i]<<" ";
			cout<<endl;
		}
		
	}
	return 0;
}
