class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool>vis(n,false);
        queue<pair<int,int>>q;//node,daddy
        q.push({0,-1});
        vis[0]=true;

        while(!q.empty()){
            auto [cur,par]=q.front();
            q.pop();

            for(auto nxt:adj[cur]){
                if(!vis[nxt]){
                    q.push({nxt,cur});
                    vis[nxt]=true;
                }
                else if(nxt!=par)return false;
            }
        }

        for(auto x:vis){
            if(!x)return false;
        }

        return true;
    }
};
