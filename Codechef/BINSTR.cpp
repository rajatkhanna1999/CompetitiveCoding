#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define PI 3.14159265358979323
#define debug(x) cout<<"Case "<<x<<": "
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long int           ll;
typedef long double             ld;
typedef unsigned long long int ull;
typedef vector <int>            vi;
typedef vector <ll>            vll;
typedef pair <int, int>        pii;

//Handle:cyber_rajat

//Power_fast To calculate the power of the string 
ll power_fast(ll n , ll m)
{
	if(n==0)
		return 1;
	else if(n==1)
		return m;
	else if(n%2==0)
		return power_fast(n/2,m*m);
	else if(n%2!=0)
		return power_fast(n/2,m*m)*m;
}

int main(int argc, char const *argv[])
{
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
	sync ;  //Fast input output
	string arr[100005];
	ll sum_arr[100005];
	ll N,Q;
	cin>>N>>Q;
	for(ll i=1;i<=N;i++)//Converting the string to integers
	{
		cin>>arr[i];
		ll total_sum_value=0;
		for(ll j=0;j<arr[i].size();j++)
		{
			if(arr[i][j]=='1')
			total_sum_value=total_sum_value+power_fast(arr[i].size()-1-j,2);
		}
		sum_arr[i]=total_sum_value;
	}

	while(Q--)
	{
		ll left,right;
		string query;
		cin>>left>>right;
		cin>>query;
		ll query_value=0;
		for(ll i=0;i<query.size();i++)
		{
			if(query[i]=='1')
			query_value=query_value+power_fast(query.size()-1-i,2);
		}
		ll j=left;
		ll Highest_ans=-1,index;
		while(j<=right)	//Choosing maximum value
		{
			ll temp=(query_value)^(sum_arr[j]);
			if(temp>Highest_ans)
				index=j,Highest_ans=temp;
			j++;
			//cout<<Highest_ans<<" "<<index<<endl;
		}
		cout<<index<<endl;
	}
	
	return 0;
}