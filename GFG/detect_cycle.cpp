//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[],vector<bool>& v,int i,int p){
        v[i] = true;
        for(auto e:adj[i]){
            cout<<e<<endl;
            if(!v[e]){
                bool ans =  dfs(adj,v,e,i);
                if(ans) return true;
            }
            else if(e!=p) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> v(V+1,false);
        for(int i=0;i<V;i++){
            if(!v[i]){
                bool ans = dfs(adj,v,i,i);
                if(ans) return true;
            }
        }
        return false;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends