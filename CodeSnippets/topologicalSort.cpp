int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}


-------------------------------------------------------------

const int N = 1e5 + 5;
int indeg[N];
vector<int> topo; //Stores lexicographically smallest toposort
vector<int> g[N];

bool toposort() //Returns 1 if there exists a toposort, 0 if there is a cycle
{   
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=1;i<=n;i++)
        for(auto &it:g[i])
            indeg[it]++;
    for(int i=1;i<=n;i++)
    {
        if(!indeg[i])
            pq.push(i);
    }
    while(!pq.empty())
    {
        int u=pq.top();
        pq.pop();
        topo.push_back(u);
        for(auto &v:g[u])
        {
            indeg[v]--;
            if(!indeg[v])
                pq.push(v);
        }
    }
    if(topo.size()<n)
        return 0;
    return 1;
}
