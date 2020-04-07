#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
using namespace std;
using namespace __gnu_pbds;

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Handle:cyber_rajat
class library
{
public:
	ll days;
	ll id;
	ll numBooksCanSend;
	ll numBooks;
	vector<pair<ll,ll> > books;
};

bool compare(library a , library b)
{
	double a1=(a.numBooksCanSend*1.0)/a.days;
	double a2=(b.numBooksCanSend*1.0)/b.days;
	return a1>a2;
}

bool compare1(pair<ll,ll>  a , pair<ll,ll> b)
{
	return a.first>b.first;
}

int main(int argc, char const *argv[])
{
	sync;
	#ifndef ONLINE_JUDGE
	freopen("f_libraries_of_the_world.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
	#endif
	ll NB,NL,D;
	cin>>NB>>NL>>D;
	ll score[NB+5]={0};
	bool visited[NB+5]={false};
	memset(visited,false,sizeof(visited));
	rep(i,NB)cin>>score[i];
	library L[NL+2];
	rep(i,NL)
	{
		cin>>L[i].numBooks>>L[i].days>>L[i].numBooksCanSend;
		L[i].id=i;
		rep(j,L[i].numBooks)
		{
			ll a;
			cin>>a;
			L[i].books.pb({score[a],a});
		}
		sort(L[i].books.begin(),L[i].books.end(),compare1);
	}
	sort(L,L+NL,compare);
	ll sum=0;
	ll maxLib=0;
	for(ll i=0;i<NL;i++)
	{
		sum+=(L[i].days);
		if(sum>D)
		{
			break;
		}
		maxLib++;
	}
	ll cnt=L[0].days;
	ll curr=0;
	cout<<maxLib<<endl;
	vector<ll> temp;
	ll jat=0;
	while(cnt<D && curr<NL)
	{
		//cout<<L[curr].id<<" ";
		for(ll i=0;i<min((D-cnt)*(L[curr].numBooksCanSend),L[curr].numBooks);i++)
		{
			if(visited[L[curr].books[i].second]==false)
			{
				temp.pb(L[curr].books[i].second);
			}
			visited[L[curr].books[i].second]=true;
		}
		//cout<<temp.size()<<endl;
		if(temp.size()!=0)
		{
			cout<<L[curr].id<<" ";
			cout<<temp.size()<<endl;
			for(int i=0;i<temp.size();i++)cout<<temp[i]<<" ";
			cout<<endl;
			jat++;
		}
		temp.clear();
		curr++;
		cnt+=L[curr].days;
	}
	cout<<endl;
	cout<<endl;
	cout<<jat<<endl;
	return 0;
}
