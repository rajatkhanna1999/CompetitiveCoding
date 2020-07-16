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
#define mem(a,b) memset(a,b,sizeof(a))
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
class dat
{
public:
    ll sum, prefixSum, suffixSum, maxSum;
    dat()
    {
        this->sum = 0;
        this->prefixSum = 0;
        this->suffixSum = 0;
        this->maxSum = 0;
    }
};

const int N=100005;
int a[N];
dat seg[N<<2];

//update as required
void merge(dat &cur, dat &l, dat &r) 
{
    cur.sum = l.sum + r.sum;
    cur.prefixSum = max(l.prefixSum, l.sum + r.prefixSum);
    cur.suffixSum = max(r.suffixSum, r.sum + l.suffixSum);
    cur.maxSum = max({l.maxSum, r.maxSum, l.suffixSum + r.prefixSum, cur.sum});
}

void build(int node, int start, int end)
{
    if(start == end)
    {
        //update as required
        seg[node].sum = a[start];
        seg[node].maxSum = max(a[start], 0);
        seg[node].prefixSum = max(a[start], 0);
        seg[node].suffixSum = max(a[start], 0);
        return ;
    }
    int mid = (start+end)>>1;
    build(node<<1, start, mid);
    build(node<<1|1, mid+1, end);
    merge(seg[node],seg[node<<1],seg[node<<1|1]);
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        //update as required
        a[idx] = val;
        seg[node].sum = val;
        seg[node].maxSum = max(val, 0);
        seg[node].prefixSum = max(val, 0);
        seg[node].suffixSum = max(val, 0);
        return;
    }
    int mid = (start + end)>>1;
    if(start <= idx && idx <= mid)
        update(node<<1, start, mid, idx, val);
    else
        update(node<<1|1, mid+1, end, idx, val);
    merge(seg[node],seg[node<<1],seg[node<<1|1]);

}

dat query(int node, int start, int end, int l, int r)
{
    if(r<start || end<l)
    {
        // range represented by a node is completely outside the given range
        dat d;
        return d;
    }
    if(l<=start && end<=r)
    {
        // range represented by a node is completely inside the given range
        return seg[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end)>>1;
    dat p1 = query(node<<1, start, mid, l, r);
    dat p2 = query(node<<1|1, mid+1, end, l, r);
    dat p;
    merge(p,p1,p2);
    return p;
}
/*
indexing or array is from 0,n-1
for(int i=0;i<n;i++)cin>>a[i];
build(1,0,n-1);
cin >> x >> y;
cout << query(1,0,n-1,x-1,y-1) << endl;
update(1,0,n-1,x-1,y);
for(int i=1; i<=2*n; i++)
{
    cout << i << ":" sp seg[i].maxi sp seg[i].secmaxi << endl;
}
*/

int main(int argc, char const *argv[])
{
	sync;
	int n, m;
	cin >> n >> m;
	rep(i,n){
		cin >> a[i];
	}
	build(1,0,n-1);
	int u, v;
    dat ans = query(1,0,n-1,0,n-1);
    cout << ans.maxSum << endl;
	rep(i,m){
        cin >> u >> v;
        update(1,0,n-1,u,v);
        ans = query(1,0,n-1,0,n-1);
        cout << ans.maxSum << endl;
	}
	return 0;
}
