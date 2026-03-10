class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
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
                    for(int i: graph[node])
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