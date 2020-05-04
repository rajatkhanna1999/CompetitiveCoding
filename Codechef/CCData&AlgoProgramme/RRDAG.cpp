//https://www.codechef.com/viewsolution/32430516
#include<bits/stdc++.h>
#define ll long long  int
#define fr(i,N) for(int i=0; i<N; i++)
#define fre(i,N) for(int i=1; i<=N; i++)
#define pb push_back
#define mp(i,j) make_pair(i,j)
#define fi first
#define se second
#define pii pair<int,int>
#define ve vector
#define piii pair<pii, int>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main()
{
   char c;
   int n;
   scanf("%d", &n);

   int a[n+1][n+1];
   int outdegree[n+1] = {0};
   bool visited[n+1] = {false};

   ve<pii> edges;
   for(int i=1; i<=n; i++){
      scanf("%c", &c);

      for(int j=1; j<=n; j++){
        scanf("%c", &c);
        // printf("%c", c);
        a[i][j] = c-'0';
        if( a[i][j] == 1)
          outdegree[i]++;
      }
   }
    
   priority_queue<int> q;  
   for(int i=1; i<=n; i++){
      if(outdegree[i] == 0 )
        q.push(i);
   }

   while(!q.empty()){
      int y = q.top();
      q.pop();

      visited[y] = true;
      for(int x=1; x<=n; x++){
        if(a[x][y]==0 && !visited[x])
          edges.push_back({x,y});
      }
      for(int x=1; x<=n; x++){
        if( a[x][y] == 0 ) continue;
        outdegree[x]--;
        if( outdegree[x] == 0 )
          q.push(x);
      }
   }

   sort(edges.begin(), edges.end());

   printf("%d\n", (int)edges.size() );
   for(int i=0; i<edges.size(); i++)
    printf("%d %d\n", edges[i].fi, edges[i].se );

}
 
    