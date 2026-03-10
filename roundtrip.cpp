#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int p,vector<vector<int>>& adj,vector<int>& vis,vector<int>& parent,int& start,int& end)
{
    vis[u] = 1;
    parent[u] = p;

    for(int v : adj[u])
    {
        if(v == p) continue;

        if(vis[v])
        {
            start = v;
            end = u;
            return true;
        }

        if(dfs(v, u, adj, vis, parent, start, end))
            return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> parent(n+1, -1);
    vector<int> vis(n+1, 0);

    int start = -1;
    int end = -1;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i] && dfs(i, -1, adj, vis, parent, start, end))
            break;
    }

    if(start == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> path;
    path.push_back(start);

    for(int v = end; v != start; v = parent[v])
        path.push_back(v);

    path.push_back(start);

    cout << path.size() << endl;
    for(int x : path) cout << x << " ";
}
