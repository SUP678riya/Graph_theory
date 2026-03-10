#include <bits/stdc++.h>
#define lli long long int
#define mod 1000000007
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<int>vis(n,0);

    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;

        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(!q.empty())
        {
            int node=q.front(); 
            q.pop();
            for(int x:adj[node])
            {
                if(!vis[x])
                {
                    vis[x]=3-vis[node]; 
                    q.push(x);
                }
                else if(vis[x]==vis[node])
                {
                    cout<<"IMPOSSIBLE";
                    return 0;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
        cout<<vis[i]<<" ";
}
