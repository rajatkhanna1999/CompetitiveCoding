// #include <bits/stdc++.h>
// #include <vector>
// #include <set>
// #include <map>
// #include <string>
// #include <cstdio>
// #include <cstdlib>
// #include <climits>
// #include <utility>
// #include <algorithm>
// #include <cmath>
// #include <queue>
// #include <stack>
// #include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
// //setbase - cout << setbase (16); cout << 100 << endl; Prints 64
// //setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
// //setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
// //cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
// using namespace std;
// using namespace __gnu_pbds;

// #define sp << " " <<
// #define mod 1000000007
// #define PI 3.14159265358979323
// #define y second
// #define x first
// #define pb push_back
// #define mp make_pair
// #define sz(a) a.size()
// #define pqueue priority_queue< ll >
// //#define pdqueue priority_queue< ll,vector<ll> ,greater< ll > >
// #define codejamDebug(x) cout<<"Case #"<<x<<": ";
// #define debug(x) cout<<#x<<" :"<<x<<endl;
// #define rep(i,n) for(long long i=0;i<n;i++)
// #define f(i,a,b) for(long long i = a; i < b; i++)
// #define fd(i,a,b) for(long long i = a; i >=b; i--)
// #define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// typedef long long int           ll;
// typedef long double             ld;
// typedef unsigned long long int ull;
// typedef vector <int>            vi;
// typedef vector <ll>            vll;
// typedef pair <int, int>        pii;
// typedef pair <ll, ll>          pll;
// typedef vector < pii >        vpii;
// typedef vector < pll >        vpll;
// typedef vector <string>         vs;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// //Handle:cyber_rajat
// typedef struct data
// {
// 	ll u, v, w, idx;

// 	data() {}
 
// 	data(ll u, ll v, ll w, ll idx) : u(u), v(v), w(w), idx(idx) {}
// }edge;

// const int N=20005;
// ll n, m;
// ll connected;
// ll root[N], sz[N];
// vector<pair<ll, ll> > g[N];
// data edges[N];

// void init()
// {
// 	for(ll i=1;i<=n;i++)
// 	{
// 		root[i]=i;
// 		sz[i]=1;
// 	}
// 	connected=n;
// }

// ll rt(ll k)
// {
// 	while(k!=root[k])
// 	{
// 		root[k]=root[root[k]];
// 		k=root[k];
// 	}
// 	return k;
// }

// void merge(ll u, ll v)
// {
// 	ll rt1=rt(u);
// 	ll rt2=rt(v);

// 	if(rt1==rt2)
// 		return;

// 	connected--;

// 	if(sz[rt1]>sz[rt2])
// 		swap(rt1, rt2);

// 	sz[rt2]+=sz[rt1];
// 	sz[rt1]=0;
// 	root[rt1]=root[rt2];
// }

// void add_edge(ll idx, ll u, ll v, ll w)
// {
// 	g[u].push_back({v, w});
// 	g[v].push_back({u, w});
// 	edges[idx]=edge(u, v, w, idx);
// }

// bool comp(data &d1, data &d2)
// {
// 	return d1.w < d2.w;
// }	

// vector<pair<ll, ll> > adj[N];

// ll kruskalMST()
// {	
// 	init();
// 	ll cost=0;
// 	sort(edges+1, edges+m+1, comp);
// 	for(ll i=1;i<=m;i++)
// 	{
// 		ll u=edges[i].u, v=edges[i].v, w=edges[i].w;
// 		ll rt1=rt(u), rt2=rt(v);
// 		if(rt1==rt2)
// 			continue;
// 		else
// 		{
// 			cost+=w;
// 			adj[u].pb({v,w});
// 			adj[v].pb({u,w});
// 			merge(rt1, rt2);
// 		}
// 	}
// 	return cost;
// }

// ll arrival[N], departure[N];

// ll dijkstra1(ll source, ll destination)
// {
// 	for(ll i=1;i<=n;i++)
// 	{
// 		arrival[i]=1e18;
// 		departure[i]=1e18;
// 	}
// 	arrival[source]=0;
// 	set<pair<ll, ll> > s;
// 	s.insert({0, source});
// 	while(!s.empty())
// 	{
// 		auto x = *(s.begin());
// 		s.erase(x);
// 		departure[x.second]=arrival[x.second];
// 		for(auto it:adj[x.second])
// 		{
// 			if(arrival[it.first] > departure[x.second] + it.second)
// 			{
// 				s.erase({arrival[it.first], it.first});
// 				arrival[it.first]=departure[x.second] + it.second;
// 				s.insert({arrival[it.first], it.first});
// 			}
// 		}
// 	}
// 	ll sum = 0;
// 	for(ll i=1; i<=n; i++)sum+=arrival[i];

// 	return sum;
// }

// ll dijkstra(ll source, ll destination)
// {
// 	for(ll i=1;i<=n;i++)
// 	{
// 		arrival[i]=1e18;
// 		departure[i]=1e18;
// 	}
// 	arrival[source]=0;
// 	set<pair<ll, ll> > s;
// 	s.insert({0, source});
// 	while(!s.empty())
// 	{
// 		auto x = *(s.begin());
// 		s.erase(x);
// 		departure[x.second]=arrival[x.second];
// 		for(auto it:g[x.second])
// 		{
// 			if(arrival[it.first] > departure[x.second] + it.second)
// 			{
// 				s.erase({arrival[it.first], it.first});
// 				arrival[it.first]=departure[x.second] + it.second;
// 				s.insert({arrival[it.first], it.first});
// 			}
// 		}
// 	}
// 	ll sum = 0;
// 	for(ll i=1; i<=n; i++)sum+=arrival[i];

// 	return sum;
// }

// int main(int argc, char const *argv[])
// {
// 	sync;
// 	ll t;
// 	cin >> t;
// 	while(t--)
// 	{
// 		memset(adj,0,sizeof(adj));
// 		memset(g,0,sizeof(g));
// 		memset(edges,0,sizeof(edges));
// 		cin >> n >> m;
// 		ll u, v, w;
// 		rep(i,m)
// 		{
// 			cin >> u >> v >> w;
// 			add_edge(i+1,u+1,v+1,w);
// 		} 
// 		ll mst = 0;
// 		mst = kruskalMST();
// 		if(connected!=1)
// 		{
// 			cout << "NO" << endl;
// 			continue;
// 		}
// 		//cout << mst sp connected << endl;
// 		ll dij1 = 0, dij2 = 0;
// 		dij1 = dijkstra(1,n);
// 		dij2 = dijkstra1(1,n);
// 		// for(int i=1; i<=n; i++)cout << arrival[i] << " ";
// 		cout << dij1 sp dij2 << endl;
// 		if(dij1==dij2)cout << "YES" << endl;
// 		else cout << "NO" << endl;
// 	}
// 	return 0;
// }
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
typedef struct data
{
    ll u, v, w, idx;

    data() {}
 
    data(ll u, ll v, ll w, ll idx) : u(u), v(v), w(w), idx(idx) {}
}edge;

const int N=20005;
ll n, m;
ll connected;
ll root[N], sz[N];
vector<pair<ll, ll> > g[N];
data edges[N];

void init()
{
    for(ll i=1;i<=n;i++)
    {
        root[i]=i;
        sz[i]=1;
    }
    connected=n;
}

ll rt(ll k)
{
    while(k!=root[k])
    {
        root[k]=root[root[k]];
        k=root[k];
    }
    return k;
}

void merge(ll u, ll v)
{
    ll rt1=rt(u);
    ll rt2=rt(v);

    if(rt1==rt2)
        return;

    connected--;

    if(sz[rt1]>sz[rt2])
        swap(rt1, rt2);

    sz[rt2]+=sz[rt1];
    sz[rt1]=0;
    root[rt1]=root[rt2];
}

void add_edge(ll idx, ll u, ll v, ll w)
{
    g[u].push_back({v, w});
    g[v].push_back({u, w});
    edges[idx]=edge(u, v, w, idx);
}

bool comp(data &d1, data &d2)
{
    return d1.w < d2.w;
}   

ll kruskalMST()
{   
    init();
    ll cost=0;
    sort(edges+1, edges+m+1, comp);
    for(ll i=1;i<=m;i++)
    {
        ll u=edges[i].u, v=edges[i].v, w=edges[i].w;
        ll rt1=rt(u), rt2=rt(v);
        if(rt1==rt2)
            continue;
        else
        {
            cost+=w;
            merge(rt1, rt2);
        }
    }
    return cost;
}

// ll arrival[N], departure[N], last[N];

// ll dijkstra(ll source, ll destination)
// {
//     for(ll i=1;i<=n;i++)
//     {
//         arrival[i]=1e18;
//         departure[i]=1e18;
//         last[i]=1e18;
//     }
//     arrival[source]=0;
//     last[source]=0;
//     set< pair<ll,pair<ll, ll> > > s;
//     s.insert({0,{0,source}});
//     while(!s.empty())
//     {
//         auto x = *(s.begin());
//         s.erase(x);
//         departure[x.second.second]=arrival[x.second.second];
//         for(auto it:g[x.second.second])
//         {
//             if((arrival[it.first]>(departure[x.second.second]+it.second))|| ((arrival[it.first]==(departure[x.second.second]+it.second)) && it.second<last[it.first]))
//             {
//                 if(s.find({arrival[it.first],{last[it.first], it.first}})!=s.end())
//                 {
//                     s.erase({arrival[it.first],{last[it.first], it.first}});
//                 }
//                 arrival[it.first]=departure[x.second.second] + it.second;
//                 last[it.first] = it.second;
//                 s.insert({arrival[it.first],{last[it.first],it.first}});
//             }
//         }
//     }
//     ll sum=0;
//     for(int i=1; i<=n; i++)sum+=last[i];

//     return sum;
// }   
ll dijkstra(ll s,ll n)
{
    vector<ll> dist(n+5,1e18);
    vector<ll> last(n+5,1e18);
    vector<ll> visited(n+5,0);
    dist[s]=0;
    last[s]=0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, s});
    while(!pq.empty())
    {
        ll v = pq.top().second;
        pq.pop();
        if(visited[v]!=0)
        continue;
        visited[v]=1;
        for (auto edg : g[v]) 
        {
            ll to = edg.first;
            ll len = edg.second;
            if ((dist[v] + len < dist[to]) || (dist[v] + len==dist[to] && last[to]>len))
            {
                dist[to] = dist[v] + len;
                last[to] = len;
                pq.push({dist[to], to});
            }
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        if(dist[i]==1e18)
        return -1;
        ans+=last[i];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    sync;
    ll t;
    cin >> t;
    while(t--)
    {
        memset(g,0,sizeof(g));
        memset(edges,0,sizeof(edges));
        cin >> n >> m;
        ll u, v, w;
        rep(i,m)
        {
            cin >> u >> v >> w;
            add_edge(i+1,u+1,v+1,w);
        } 
        ll mst = 0;
        mst = kruskalMST();
        if(connected!=1)
        {
            cout << "NO" << endl;
            continue;
        }
        //cout << mst sp connected << endl;
        ll dij1 = 0;
        dij1 = dijkstra(1,n);
        //cout << mst sp dij1 << endl;
        if(dij1==mst)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
