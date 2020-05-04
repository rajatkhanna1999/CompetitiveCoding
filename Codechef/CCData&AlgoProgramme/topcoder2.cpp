#include <bits/stdc++.h>
using namespace std;

#define sp << " " <<
#define mod 1000000007
#define PI 3.14159265358979323
#define y second
#define x first
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define pqueue priority_queue< ll >
//#define pdqueue priority_queue< ll,vector<ll> ,greater< ll > >
#define codejamDebug(x) cout<<"Case #"<<x<<": ";
#define debug(x) cout<<#x<<" :"<<x<<endl;
#define rep(i,n) for(long long i=0;i<n;i++)
#define f(i,a,b) for(long long i = a; i < b; i++)
#define fd(i,a,b) for(long long i = a; i >=b; i--)
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
class ThreeNeighbors
{
public:
	vector<string> construct(int n)
	{
		vector<string> v(50);
		int temp = n;
		int q = temp/24;
		int rem = temp%4;
		bool flag=false;
		int togg = 0;
		rep(i,50)v[i]="";
		int i=0, cnt=0;
		while(temp>0)
		{
			if(flag && cnt==0 && togg==0)
			{
				for(int j=0; j<50; j+=4)
				{
					v[i]+="....";
					v[i+1]+="....";
					temp--;
					if(temp<=0)
					{
						break;
					}
				}
				i+=2;
			}
			if(togg==0)
			{
				v[i]+=".X";
				v[i+1]+="XX";
				temp--;
				togg^=1;
			}
			else
			{
				v[i]+="..";
				v[i+1]+="X.";
				temp--;
				togg^=1;
			}
			if(togg==0)cnt++;
			if(cnt==12)
			{
				cnt=0;
				togg=0;
				flag=true;
				if(temp>0)
				{
					v[i]+=".X";
					v[i+1]+="XX";
					temp--;
				}
				i+=2;
			}
		}
		// rep(i,v.size())
		// {
		// 	rep(j,v[i].size())
		// 	{
		// 		cout << v[i][j];
		// 	}
		// 	cout << endl;
		// }
		// cout<<endl;
		vector<string> answer;
		for(int j=0; j<50; j+=2)
		{
			if(v[j].size()==0)
			{
				break;
			}
			else
			{
				answer.pb(v[j]);
				answer.pb(v[j+1]);
			}
		}
		int len = answer.size();
		if(len>2 && answer[len-1].size()!=50)
		{
			while(answer[len-1].size()!=50)
			{
				answer[len-1]+="XX";
				answer[len-2]+="XX";
			}
		}
		return answer;
	}
};

int main(int argc, char const *argv[])
{
	sync;
	int n;
	cin >> n;
	ThreeNeighbors solve;
	vector<string> ans=solve.construct(n);
	rep(i,ans.size())
	{
		rep(j,ans[i].size())
		{
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}
