//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int rows, int cols){
        //pair<int,int> ans;
        int i=0, j=0, cur_i, cur_j, dir=1;
        //1: up
        //2: right
        //3: down
        //4; left
                
        //      dir  1   2  3  4
        int dy[] = {0, 1, 0, -1}; //col
        int dx[] = {-1, 0, 1, 0}; //row
        
        while(i>=0 && j>=0 && i<rows && j<cols){
            cur_i=i; cur_j=j;
            if(matrix[i][j]==0){
                //same dir
                i+=dx[dir];
                j+=dy[dir];
                
            }else{
                matrix[i][j]=0;
                dir=(dir+1)%4;
                i+=dx[dir];
                j+=dy[dir];
            }
        }
        
        return {cur_i, cur_j};
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends
