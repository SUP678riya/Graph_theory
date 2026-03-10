#include <bits/stdc++.h>
#define lli long long int
#define mod 1000000007

using namespace std;

void dfs(int i,vector<int>&vis1, vector<vector<int>>&adj1,stack<int>&st)
    {
        vis1[i]=1;
        for(int child:adj1[i])
        {
            if(!vis1[child])
            {
                dfs(child,vis1,adj1,st);
            }
        }
        st.push(i);
    }
    
    void dfs2(int node,vector<int>&vis2, vector<vector<int>>&adj2, vector<int>&ans)
    {
        vis2[node]=1;
        ans.push_back(node);

        for(int child:adj2[node])
        {
            if(!vis2[child])
            {
                dfs2(child,vis2,adj2,ans);
            }
        }
    }

int main() 
{
	 int n,m;
	 cin>>n>>m;
	 vector<vector<int>>adj1(n);
	 vector<vector<int>>adj2(n);
	 for(int i=0;i<m;i++)
	 {
	 	int u,v;
	 	cin>>u>>v;
	 	adj1[u-1].push_back(v-1);
	 	adj2[v-1].push_back(u-1);
	 }
	 vector<int>vis1(n,0);
	 vector<int>vis2(n,0);
	 stack<int>st;
     for(int i=0;i<n;i++)
     {
        if(!vis1[i])
        {
            dfs(i,vis1,adj1,st);
        }
     }
     vector<vector<int>>res;
     while(!st.empty())
     {
     	vector<int>ans;
     	int node=st.top();
        st.pop();
        if(vis2[node]) continue;
        else
        {
            dfs2(node,vis2,adj2,ans);
            res.push_back(ans);
        }
     }
     cout<<res.size()<<endl;
     vector<int>v(n);
     for(int i=0;i<res.size();i++)
     {
     	for(int j=0;j<res[i].size();j++)
     	{
     		v[res[i][j]]=i+1;
     	}
     }
     for(int i=0;i<n;i++)
     {
     	cout<<v[i]<<" ";
     }



    return 0;
}






