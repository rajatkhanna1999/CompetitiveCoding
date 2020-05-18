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

ll f1(ll mid, ll dif)
{
    return (mid*(mid+1) + mid*dif);
    
}

ll f2(ll mid,ll dif)
{
    return (mid*mid + mid*dif);
    
}


int main() 
{
	sync;
    int T;
    ll L,R,dif,z,N,y,count;
    cin >> T;
    for(int x  = 1 ; x <= T ; x++)
    {
        count = 0;
        cin>>L>>R;
        z = abs(L-R);
        dif = 2*z;
        dif = sqrtl(dif);
        
        if((dif*(dif+1))/2 < z)
            dif++;
        
        if((dif*(dif+1))/2 < z)
            dif++;
        
        
        if((dif*(dif+1))/2 > z)
            dif--;
            
        if((dif*(dif+1))/2 > z)
            dif--;
            
        if(L>=R)
            L = L - (dif*(dif+1))/2;
            
        else
            R = R - (dif*(dif+1))/2;
            
        y = abs(L-R);
        
        
        ll start = 0;
        ll end = 1000000000;
        ll mid = (start + end)/2;
        
        while(start < end)
        {
            mid = (start + end)/2;
            if(L>=R)
            {
                if(f2(mid,dif)>L || f1(mid,dif)>R)
                {
                    end = mid;
                }
                
                else if(f2(mid,dif)<=L && f1(mid,dif)<=R)
                {
                    if(f2(mid+1,dif)>L || f1(mid+1,dif)>R)
                    {
                        L -= f2(mid,dif);
                        R -= f1(mid,dif);
                        break;
                    }
                    
                    else
                        start = mid;
                }
                
            }
            else
            {
                if(f2(mid,dif)>R || f1(mid,dif)>L)
                {
                    end = mid;
                }
                
                else if(f2(mid,dif)<=R && f1(mid,dif)<=L)
                {
                    if(f2(mid+1,dif)>R || f1(mid+1,dif)>L)
                    {
                        R -= f2(mid,dif);
                        L -= f1(mid,dif);
                        break;
                    }
                    else
                        start = mid;
                }
                
            }
        }
        
        ll ans = dif+2*mid;
        if(L>=R)
        {
            if(L>=dif+2*mid+1)
            {
                L-=dif+2*mid + 1;
                ans++;
            }
            
            if(R>=dif+2*mid+2)
            {
                R-=dif+2*mid+2;
                ans++;
            }
        }
        
        else
        {
            if(R>=dif+2*mid+1)
            {
                R-=dif+2*mid + 1;
                ans++;
            }
            
            if(L>=dif+2*mid+2)
            {
                L-=dif+2*mid+2;
                ans++;
            }
        }
        
        codejamDebug(x);  
        cout<<ans<<" "<<L<<" "<<R<<endl;
    }
	return 0;
}