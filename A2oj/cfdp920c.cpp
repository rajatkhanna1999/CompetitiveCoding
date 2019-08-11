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

/*char s[200010];
int main()
{
	scanf("%s",s+1);
	int lst=0;
	for (int i=1;i<n;i++)
	{
		if (s[i]=='0')
		{
			sort(a+lst,a+i);
			lst=i;
		}
	}
	sort(a+lst,a+n);
	for (int i=1;i<n;i++)
	{
		if (a[i]<a[i-1])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}*/


int main(int argc, char const *argv[])
{
	sync;
	ll n;
	cin>>n;
	ll arr[n+5]={0};
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	string s;
	cin>>s;
	ll index=0;
	for(ll i=0;i<(n-1);i++)
	{
		if(s[i]=='0')
		{
			sort(arr+index,arr+i+1);
			index = i+1;
		}
	}
	sort(arr+index,arr+n);
	for(ll i=0;i<(n-1);i++)
	{
		if(arr[i]>arr[i+1])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}