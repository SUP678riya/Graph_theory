#include <bits/stdc++.h>
#define lli long long int
#define mod 1000000007
 
using namespace std;
 
 
int main() {
	int n,m;
		cin>>n>>m;
		vector<vector<pair<int,int>>>adj(n);
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			adj[a-1].push_back({b-1,c});
			adj[b-1].push_back({a-1,c});
		}
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
	    vector<int> vis(n, 0);
 
	    pq.push({0,0});
	    long long sum = 0;
        int count=0;
 
	    while(!pq.empty())
	    {
	        int weight = pq.top().first;
	        int node = pq.top().second;
            pq.pop();
 
	        if(vis[node]) continue;
 
	        vis[node] = 1;
	        sum += weight;
            count++;
 
	        for(auto it : adj[node])
	        {
	            int adjNode = it.first;
	            int edW = it.second;
 
	            if(!vis[adjNode])
	            {
	                pq.push({edW, adjNode});
	            }
	        }
	    }
        if(count==n)
        {
            cout<<sum;
        }
        else
        {
            cout<<"IMPOSSIBLE";
        }
    
    return 0;
}