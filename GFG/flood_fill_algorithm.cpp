//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<bool>> v(image.size(),vector<bool>(image[0].size(),0));
        v[sr][sc] = true;
        vector<int> a{-1,0,+1,0};
        vector<int> b{0,-1,0,+1};
        while(!q.empty()){
            auto e = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr = a[i]+e.first;
                int nc = b[i]+e.second;
                if(nr>=0 && nc>=0 && nr<image.size() && nc<image[0].size()){
                    if(!v[nr][nc] && image[nr][nc] == image[sr][sc]){
                        image[nr][nc] = newColor;
                        v[nr][nc] = true;
                        q.push({nr,nc});
                    }
                }
            }
        }
        image[sr][sc] = newColor;
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends