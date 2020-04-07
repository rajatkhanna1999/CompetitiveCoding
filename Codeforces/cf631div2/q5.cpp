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
	int t;
    cin>>t;
    while(t--)
    {
    	ll n;
        cin >> n;
        ll maxim = 0,a[n+1];
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
            maxim = max(maxim,a[i]);
        }     
        ll col[maxim+1]={0},temp = n -maxim,dol[temp+1]={0};
        for(int i = 1 ; i <= maxim ; i++ )
        {
            col[a[i]] = 1;
        }
        for(int j = maxim+1; j <=n; j++)
        {
            if(a[j]>temp)
                break;
            dol[a[j]]=1;
        }
        int flag = 0, ans=0;
        for(int i = 1; i<=maxim; i++)
        {
            if(col[i]==0)
            {
                flag =1;
                break;
            }
        }
        if(!flag)
        {
            for(int i = 1; i<=temp; i++)
            {
                if(dol[i]==0)
                {
                    flag =1;
                    break;
                }   
            }
            if(flag==0)
            {
                ans = 1;
            }
        }
        
        ll e[temp+1]={0}, f[maxim+1]={0};
        
        for(int j = 1; j <=temp; j++)
        {
            if(a[j]>temp)
                break;
            e[a[j]]=1;
        }
        
        for(int i = temp + 1; i <= n; i++ )
        {
            f[a[i]] = 1;
        }
        
        flag = 0;
        int ans2=0;
        for(int i = 1 ; i<= temp ; i++)
        {
            if(e[i]==0)
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            for(int i = 1; i<=maxim; i++)
            {
                if(f[i]==0)
                {
                    flag =1;
                    break;
                }   
            }
            if(flag == 0)
                ans2 =1;
        }
        
        if(maxim==temp && flag == 0)
        {
            cout<<1<<endl;
            cout<<maxim<<" "<<temp<<endl;
            continue;
        }

        cout<<ans+ans2<<endl;

        if(ans==1)
            cout<<maxim<<" "<<temp<<endl;
        if(ans2 == 1)
            cout<<temp<<" "<<maxim<<endl;
        
    }
	return 0;
}
