class Solution {
public:
    void bfs(int i,vector<vector<int>>& adj,vector<bool>& vis){
        vis[i]=true;
        queue<int>q;
        q.push(i);

        while(!q.empty()){
            int v=q.front();
            q.pop();

            for(auto u:adj[v]){
                if(!vis[u]){
                    q.push(u);
                    vis[u]=true;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool>vis(n,false);
        int ct=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,adj,vis);
                ct++;
            }
        }

        return ct;
    }
};
