//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(grid.size(),vector<int>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    q.push_back({i,j});
                    count++;
                    visited[i][j] = true;
                    while(!q.empty()){
                        auto e:q.front();
                        q.pop();
                        for(int k=-1;k<=1;k++){
                            for(int l=-1;l<=1;l++){
                                int nr = i+k;
                                int nc = j+l;
                                if(((nr>0 && nc>0) && (nr<grid.size() && nc<grid[0].size())) && (!visited[nr][nc] && graph[nr][nc]) == '1'){
                                    visited[nr][nc] = true;
                                    q.push_push({nr,nc});
                                }
                            }
                        }
                    }
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