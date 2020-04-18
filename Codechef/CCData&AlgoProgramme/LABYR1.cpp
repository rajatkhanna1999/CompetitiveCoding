#include <bits/stdc++.h>

typedef long long  ll;

#define MOD               1000000007
#define scll(t)               scanf("%lld",&t)
#define sc(t)                 scanf("%d",&t)
#define max(a,b)         (a>=b?a:b)
#define min(a,b)          (a<b?a:b)
#define gc                    getchar_unlocked
#define mp                   make_pair
#define pb                    push_back
#define Size(a)            int((a).size())
#define F                     first
#define S                     second

using namespace std;


int R, C, ans, len;
char grid[1001][1001];
int visited[1001][1001];
int dist[1001][1001];//For finding the length of path
// for going up, down, left, right from current cell
int dr[4] = {0, 0, 1,-1};
int dc[4] = {1,-1, 0, 0};

pair<int,int> diameterEnd;


bool inGrid(pair<int,int>& g)
{
    return (g.F>=0 && g.F<R && g.S>=0 && g.S<C);
}

void bfs(pair<int,int> start)
{
    queue<pair<int,int> > q;
    q.push(start);
    while(!q.empty())
    {
        pair<int,int> cur = q.front(),next;
        q.pop();
        for(int i=0;i<4;i++)
        {
            next.F = cur.F + dr[i];
            next.S = cur.S + dc[i];
            if(inGrid(next))
            {
                if(grid[next.F][next.S] == '.' && !visited[next.F][next.S])
                {
                    visited[next.F][next.S] = 1;
                    dist[next.F][next.S] =  dist[cur.F][cur.S] + 1;
                    if(dist[next.F][next.S]>len)
                    {
                        len = dist[next.F][next.S];
                        diameterEnd = next;
                    }
                    q.push(next);
                }

            }
        }

    }
}

int main()
{
    int t,i,j,present;
    sc(t);
    while(t--)
    {
        len = 0;
        present = 0;
        pair<int,int>  St;
        sc(C);
        sc(R);
        memset(visited,0,sizeof visited);
        for(i=0;i<R;i++)
        {
            scanf("%s",grid[i]);
        }
        
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                if(grid[i][j] == '.')
                {
                    St = mp(i,j);
                    dist[i][j] = 0;
                    present = 1;
                    break;
                }
            }
            if(present)
                break;
        }
        // first bfs call
        bfs(St);
        memset(visited,0,sizeof visited);
        dist[diameterEnd.F][diameterEnd.S] = 0;
        len = 0;
        //second bfs call
        bfs(diameterEnd);


        printf("Maximum rope length is %d.\n",len);
    }

}