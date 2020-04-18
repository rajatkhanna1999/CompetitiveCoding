const int N = 1e4 + 1;
int diameter[N]; 
vector<int> adj[N];

int bfs(int init, int n) 
{ 
    // Initializing queue 
    queue<int> q; 
    q.push(init); 
  
    int visited[n + 1]; 
    for (int i = 0; i <= n; i++) { 
        visited[i] = 0; 
        diameter[i] = 0; 
    } 
  
    // Pushing each node in queue 
    q.push(init); 
  
    // Mark the traversed node visited 
    visited[init] = 1; 
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
        for (int i = 0; i < adj[u].size(); i++) { 
            if (visited[adj[u][i]] == 0) { 
                visited[adj[u][i]] = 1; 
  
                // Considering weight of edges equal to 1 
                diameter[adj[u][i]] += diameter[u] + 1; 
                q.push(adj[u][i]); 
            } 
        } 
    } 
  
    // return index of max value in diameter 
    return int(max_element(diameter + 1, diameter + n + 1) - diameter); 
} 
  
int findDiameter(int n) 
{ 
    int init = bfs(1, n); 
    int val = bfs(init, n); 
    return diameter[val]; 
} 

findDiameter(n)