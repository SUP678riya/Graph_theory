class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n,0);
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
            {
                indeg[edges[i]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            vis[node]=1;
            int x=edges[node];
            if(x!=-1)
            {
                indeg[x]--;
                if(indeg[x]==0)
                {
                    q.push(x);
                }
            }
        }
        int ans=-1;
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    int cnt=0;
                    int node=i;
                    while(!vis[node])
                    {
                        vis[node]=1;
                        node=edges[node];
                        cnt++;
                    }
                    ans=max(ans,cnt);
                }
            }
        return ans;
    }
};

