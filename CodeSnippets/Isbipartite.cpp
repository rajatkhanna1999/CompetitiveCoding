int n;
vector<vector<int>> adj;

vector<int> side(n, -1);
bool is_bipartite = true;
queue<int> q;
for (int st = 0; st < n; ++st) {
    if (side[st] == -1) {
        q.push(st);
        side[st] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : adj[v]) {
                if (side[u] == -1) {
                    side[u] = side[v] ^ 1
                    q.push(u);
                } else {
                    is_bipartite &= side[u] != side[v];
                }
            }
        }
    }
}

cout << (is_bipartite ? "YES" : "NO") << endl;

-------------------------------------------------------
Divide into components 
const int N = 5005;
vector<int> adj[N];
vector<pair<vector<int>,vector<int> > > comp;

bool IsBipartite(int n){
    vector<int> side(n+1, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 1; st <= n; ++st) {
        if (side[st] == -1) {
            q.push(st);
            vector<int> v1, v2;
            side[st] = 0;
            v1.pb(st);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u : adj[v]) {
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        if(side[u] == 1){
                            v2.pb(u);
                        }else{
                            v1.pb(u);
                        }
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
            comp.pb({v1,v2});
        }
    }
    return is_bipartite;
}