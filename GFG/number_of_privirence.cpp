//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs_helper(map<int,set<int>> graph, vector<bool> &visited,int source){
        visited[source] = true;
        for(auto e:graph[source]){
            if(!visited[e]){
                dfs_helper(graph,visited,e);
            }
        }
        return;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        map<int,set<int>> graph;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=j && adj[i][j]!= 0) {
                    graph[i].insert(j);
                }
            }
        }
        vector<bool> visited(V,false);
        int count = 0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs_helper(graph,visited,i);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends


