//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> grid)
    {
        // Code here
        queue<pair<pair<int, int>, pair<int, int>>> s;
        vector<int> v1{-1, 0, +1, 0};
        vector<int> v2{0, -1, 0, +1};
        int n = grid.size();
        int m = grid[0].size();
        int p = 0;
        vector<vector<bool>> v(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    p++;
                    for (int k = 0; k < 4; k++)
                    {
                        int r = i + v1[k];
                        int c = j + v2[k];
                        if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 2 && !v[i][j])
                        {
                            s.push({{i, j}, {r, c}});
                            v[i][j] = true;
                        }
                    }
                }
            }
        }
        int count = 0;
        int si = s.size();
        if (si)
            count++;
        if (p == 0)
            return 0;
        s.push({{-1, -1}, {-1, -1}});
        while (!s.empty())
        {
            auto e = s.front();
            s.pop();
            if (e.first.first == -1)
            {
                if (s.empty())
                {
                    if (p == 0)
                        return count;
                    return -1;
                }
                s.push({{-1, -1}, {-1, -1}});
                count++;
                continue;
            }
            p--;
            
            int i = e.first.first;
            int j = e.first.second;
            grid[i][j] = 2;
            for (int k = 0; k < 4; k++)
            {
                int r = i + v1[k];
                int c = j + v2[k];
                if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1 && !v[r][c])
                {
                    s.push({{i, j}, {r, c}});
                    v[r][c] = true;
                }
            }
        }
        if (count)
            return count;
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends