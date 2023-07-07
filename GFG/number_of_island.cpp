//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited,int l,int m){
        visited[l][m] = true;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int r = l+i;
                int c = m+j;
                if(r>=0 && c>=0 &&r<grid.size() && c<grid[0].size() &&grid[r][c] == '1' && !visited[r][c]){
                    dfs(grid,visited,r,c);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        vector<vector<bool>> visited(grid.size(),vector<bool> (grid[0].size(),false));
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends