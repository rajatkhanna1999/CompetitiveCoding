#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
 
#define mp make_pair
#define x first
#define y second
 
using namespace std ;
 
typedef long long LL ;
 
const int N = 110, mod = 1000000007 ;
 
int n, m ;
char g[N][N] ;
bool st[1000] ;
 
int main ()
{
    cin >> n >> m ;
    for (int i = 0; i < n; i ++ ) scanf ("%s", g[i]) ;
    LL res = 1 ;
    for (int i = 0; i < m; i ++ )
    {
        memset (st, 0, sizeof st) ;
        int s = 0 ;
        for (int j = 0; j < n; j ++ )
            if (!st[g[j][i]])
            {
                s ++ ;
                st[g[j][i]] = 1 ;
            }
        res = res * s % mod ;
    }
    cout << res << endl ;
    return 0 ;
}