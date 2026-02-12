#include <bits/stdc++.h>
#define lli long long int
#define mod 1000000007

using namespace std;

int bfs(vector<vector<int>>&adj,int n)
{
	vector<int>vis(n,0);
	vector<int>dist(n,-1);
	queue<int>q;
	q.push(0);
	dist[0]=0;
	vis[0]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int x:adj[node])
		{
			if(!vis[x])
			{
				vis[x]=1;
				dist[x]=dist[node]+1;
				q.push(x);
			}
		}
	}
	return dist[n-1];
}

int main() 
{
	int n,m;
		cin>>n>>m;
		vector<vector<int>>adj_train(n);
		vector<vector<int>>adj_bus(n);
		vector<vector<int>> mat(n, vector<int>(n, 0));
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			adj_train[u-1].push_back(v-1);
			adj_train[v-1].push_back(u-1);
			mat[u-1][v-1]=mat[v-1][u-1]=1;
		}
        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<n;j++)
        	{
        		if(i!=j && mat[i][j]==0)
        			{
        				adj_bus[i].push_back(j);
        			}
        	}
        }
        if(mat[0][n-1]==1)
        {
        	int bus=bfs(adj_bus,n);
        	cout<<bus;
        }
        else
        {
        	int tr=bfs(adj_train,n);
        	cout<<tr;
        }
        return 0;
}