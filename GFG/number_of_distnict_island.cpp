//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> g,int i,int j,vector<vector<bool>>& v,int p1,int p2,set<pair<int,int>>& s){
        v[i][j] = true;
        s.insert({abs(p1-i),abs(p2-j)});
        vector<int> v1{0,+1,0,-1};
        vector<int> v2{+1,0,-1,0};
        for(int k=0;k<4;k++){
            int r = i+v1[k];
            int c = j+v2[k];
            if(r>=0 && c>=0 && r<g.size() && c<g[0].size() && g[r][c] == 1 && !v[r][c]){
                dfs(g,r,c,v,p1,p2,s); 
            }
        }
        return;
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> v(grid.size(),vector<bool>(grid[0].size(),false));
        set<set<pair<int,int>>> s;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!v[i][j] && grid[i][j]){
                    set<pair<int,int>> p;
                    dfs(grid,i,j,v,i,j,p);
                    s.insert(p);
                }
            }
        }
        for(auto e:s){
            for(auto a:e){
                cout<<"["<<a.first<<","<<a.second<<"]"<<" ";
            }
            cout<<endl;
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t=1;
    // cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends