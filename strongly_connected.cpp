//Position this line where user code will be pasted.
class Solution {
  public:
    
    void dfs(int i,vector<int>&vis, vector<vector<int>>&adj,stack<int>&st)
    {
        vis[i]=1;
        for(int child:adj[i])
        {
            if(!vis[child])
            {
                dfs(child,vis,adj,st);
            }
        }
        st.push(i);
    }
    
    void dfs2(int node,vector<int>&vis2, vector<vector<int>>&adj2)
    {
        vis2[node]=1;
        for(int child:adj2[node])
        {
            if(!vis2[child])
            {
                dfs2(child,vis2,adj2);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int>vis2(n,0);
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,st);
            }
        }
        
        vector<vector<int>>adj2(n);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                int a=adj[i][j];
                adj2[a].push_back(i);
            }
        }
        int count=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(vis2[node]) continue;
            else
            {
                dfs2(node,vis2,adj2);
                count++;
            }
        }
        return count;
        
    }
};