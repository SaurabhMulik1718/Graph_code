//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(map<pair<int,int>,set<pair<int,int>>> m,int r,int j,vector<vector<bool>>& v){
        v[r][j] = true;
        for(auto e:m[{r,j}]){
            if(!v[e.first][e.second]){
                dfs(m,e.first,e.second,v);
            }
        }
    }
    vector<vector<char>> fill(int n, int mi, vector<vector<char>> mat)
    {
        // code hereve
        map<pair<int,int>,set<pair<int,int>>> m;
        vector<int> v1{-1,0,+1,0};
        vector<int> v2{0,-1,0,+1};
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 'X') continue;
                for(int k=0;k<4;k++){
                    int r = i+v1[k];
                    int c = j+v2[k];
                    if(r>=0 && c>=0 && r<mat.size() && c<mat[0].size() && mat[r][c] != 'X'){
                        m[{i,j}].insert({r,c});
                        m[{r,c}].insert({i,j});
                    }
                }
            }
        }
        vector<vector<bool>> v(mat.size(),vector<bool>(mat[0].size(),false));
        for(int i=0;i<mat.size();i++){
            if(!v[i][0] && mat[i][0] != 'X'){
                dfs(m,i,0,v);
            }
        }
        for(int i=0;i<mat[0].size();i++){
            if(!v[0][i] && mat[0][i] != 'X'){
                dfs(m,0,i,v);
            }
        }
        for(int i=mat.size()-1;i>=0;i--){
            if(!v[i][mat[0].size()-1] && mat[i][mat[0].size()-1] != 'X'){
                dfs(m,i,mat[0].size()-1,v);
            }
        }
        for(int i=mat[0].size()-1;i>=0;i--){
            if(!v[mat.size()-1][i] && mat[mat.size()-1][i] != 'X'){
                dfs(m,mat.size()-1,i,v);
            }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(!v[i][j]) mat[i][j] = 'X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends