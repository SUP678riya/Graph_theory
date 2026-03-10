#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,long long>>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b; long long c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<vector<long long>> dist(n+1);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        auto it = pq.top();
        int d=it.first;
        int u=it.second;
        pq.pop();
        if(dist[u].size() >= k) continue;
        dist[u].push_back(d);
        for(auto [v,w] : adj[u])
        {
            pq.push({d+w, v});
        }
    }
    for(long long x : dist[n])
        cout<<x<<" ";
}
