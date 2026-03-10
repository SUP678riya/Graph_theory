#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<long long> dist(n+1, INT_MAX);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(dis>dist[node]) continue;

        for(auto it:adj[node])
        {
            int edge=(*it).first;
            int w=(*it).second;
            if(dist[node] + w < dist[edge]){
                dist[edge] = dist[node] + w;
                pq.push({dist[edge], edge});
            }
        }
    }

}
