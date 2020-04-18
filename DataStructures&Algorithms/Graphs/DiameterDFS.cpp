//adjacency list
//adj[i] contains all neighbors of i
//Credits:https://codeforces.com/blog/entry/20935
const int N = 1e5 + 5;
vector<int> adj[N];

//functions as defined above
int f[N],g[N],diameter;

//pV is parent of node V
void dfs(int V, int pV){
    //this vector will store f for all children of V
    vector<int> fValues;

    //traverse over all children
    for(auto v: adj[V])
    {
        if(v == pV)
        {
            continue;
        }
        dfs(v, V);
        fValues.push_back(f[v]);
    }

    //sort to get top two values
    //you can also get top two values without sorting(think about it) in O(n)
    //current complexity is n log n
    sort(fValues.begin(),fValues.end());

    //update f for current node
    f[V] = 1;
    if(!fValues.empty()) f[V] += fValues.back();

    if(fValues.size()>=2)
    {
         g[V] = 2 + fValues.back() + fValues[fValues.size()-2];
    }

    diameter = max(diameter, max(f[V], g[V]));
}