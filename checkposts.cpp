#include <bits/stdc++.h>
#define lli long long int
#define mod 1000000007
using namespace std;

void dfs(int i, vector<int>& vis1, vector<vector<int>>& adj1, stack<int>& st)
{
    vis1[i]=1;
    for(int child:adj1[i])
        if(!vis1[child])
            dfs(child,vis1,adj1,st);
    st.push(i);
}

void dfs2(int node, vector<int>& vis2, vector<vector<int>>& adj2, vector<int>& comp)
{
    vis2[node]=1;
    comp.push_back(node);
    for(int child:adj2[node])
        if(!vis2[child])
            dfs2(child,vis2,adj2,comp);
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj1(n), adj2(n);
    vector<int> cost(n);

    for(int i=0;i<n;i++) cin>>cost[i];

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj1[u-1].push_back(v-1);
        adj2[v-1].push_back(u-1);
    }

    vector<int> vis1(n,0), vis2(n,0);
    stack<int> st;

    for(int i=0;i<n;i++)
        if(!vis1[i])
            dfs(i,vis1,adj1,st);

    long long sum=0;
    long long ways=1;

    while(!st.empty())
    {
        int node=st.top(); st.pop();
        if(vis2[node]) continue;

        vector<int> comp;
        dfs2(node,vis2,adj2,comp);

        int mini=INT_MAX;
        int count=0;
        for(int x:comp)
        {
            if(cost[x] < mini)
            {
                mini = cost[x];
                count = 1;
            }
            else if(cost[x] == mini)
                count++;
        }

        sum += mini;
        ways = (ways * count) % mod;
    }

    cout<<sum<<" "<<ways;
}
