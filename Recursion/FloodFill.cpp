//Flood-fill algo

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    void dfs(vector<vector<int>>&image, int sr, int sc, int source , int rows , int col , int newColor)
    {
        
        if( sr<0 || sr>=rows || sc<0 || sc>=col )
            return;
        if(image[sr][sc] != source)
            return;
        image[sr][sc] = newColor;
        
        dfs(image , sr-1 ,sc ,source ,rows, col, newColor); //top
        dfs(image , sr+1 ,sc ,source ,rows, col, newColor); //down
        dfs(image , sr ,sc-1 , source ,rows, col, newColor); //left
        dfs(image , sr ,sc+1 ,source ,rows, col ,newColor);  //right
        
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int source = image[sr][sc];
         if(newColor == source)
            return image;
         int rows = image.size();
         int col = image[0].size();
         dfs(image,sr,sc,source,rows, col,newColor);
         return image;
    }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends
