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

int main(int argc, char const *argv[])
{
	sync;
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/
    
    int t,T=1;
    cin >> t;
    while(t--)
    {
    	ll N;
    	codejamDebug(T);
    	cout << endl;
    	T++;
        cin >> N;
        ll temp = N, bits = 0;
        while(temp>0)
        {
            temp = temp/2;
            bits++;
        }
        bits--;
        ll kyu = N-bits;
        vector<ll> a;
        while(kyu>0)
        {
            a.pb(kyu%2);
            kyu = kyu/2;
        }
        ll l=a.size(), cnt=0, start = 1;
        for(ll i=0; i<l; i++)
        {
            if(a[i]==0)
            {
                a[i] = -1;
                cnt++;
            }
        }
        bits-=cnt;
        for(ll i=1; i<=l; i++)
        {
            ll end = i;
            if(a[i-1]==-1)
            {
                end = 1;
                if(start!=1)
                {
                    cout<<i sp i<<endl;
                    continue;
                }
            }
            if(start == 1)
            {
                for(ll j=1; j<=end; j++)
                {
                    cout<<i sp j<<endl;
                }
                start = i+1;
                if(end == 1)
                {
                    start = 1;
                }
            }
            else
            {
                for(ll j=end; j>=1; j--)
                {
                    cout<<i sp j<<endl;
                }
                start = 1;
            }
        }
        if(start == 1)
        {
            for(ll i=1; i<=bits; i++)
            {
                cout<<(l+i) sp 1<<endl;
            }
        }
        else
        {
            for(ll i=1; i<=bits; i++)
            {
                cout<<(l+i) sp (l+i)<<endl;
            }
        }
    }
    return 0;
}