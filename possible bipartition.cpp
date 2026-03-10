class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n);
        for(int i=0;i<dislikes.size();i++)
        {
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        vector<int>color(n,-1);
        queue<int>q;
        for(int start=0;start<n;start++)
        {
            if(color[start]==-1)
            {
                color[start]=0;
                q.push(start);
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(int i: adj[node])
                    {
                        if(color[i]==-1)
                        {
                            if(color[node]==0)
                            {
                                color[i]=1;
                            }
                            else
                            {
                                color[i]=0;
                            }
                            q.push(i);
                        }
                        else if(color[i]!=-1 && color[i]==color[node])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};