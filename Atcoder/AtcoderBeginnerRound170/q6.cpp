#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 1e5 + 5;
 
int n, m, k;
int x11, y11, x2, y2;
int dx[4]={-1, +1, 0, 0};
int dy[4]={0, 0, +1, -1};
vector<vector<char> > a;
vector<vector<int> > vis, ways, dist;
 
void bfs(int x, int y)
{
	queue<pair<int, int> > q;
	q.push({x, y});
	vis[x][y] = 1;
	dist[x][y] = 0;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int dir=0;dir<4;dir++)
		{
			for(int len = 1; len <= k; len++)
			{
				int nx=x+dx[dir] * len;
				int ny=y+dy[dir] * len;
				if(nx<1 || ny<1 || nx>n || ny>m)
					break;
				if(vis[nx][ny] && dist[x][y] + 1 > dist[nx][ny])
					break;
				if(a[nx][ny] == '@')
					break;
				if(vis[nx][ny])
					continue;
				dist[nx][ny]=dist[x][y]+1;
				vis[nx][ny]=1;
				q.push({nx, ny});
			}
		}
	}
}
 
int32_t main()
{
	IOS;
	cin >> n >> m >> k;
	cin >> x11 >> y11 >> x2 >> y2;
	a = vector<vector<char> > (n + 1, vector<char> (m + 1));
	vis = ways = dist = vector<vector<int> > (n + 1, vector<int> (m + 1, 0));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	bfs(x11, y11);
	if(!vis[x2][y2])
		cout << -1;
	else
		cout << dist[x2][y2];
	return 0;
}
