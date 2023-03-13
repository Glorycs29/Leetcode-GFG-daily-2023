class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int result=0;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                
                if(i>0 && j>0 && matrix[i][j]>0)
                matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j],               matrix[i][j-1])) + 1;

            result +=  matrix[i][j];
                
            }

        }
        return result;
    }
};



/*
Let the matrix be
1 1
1 1
There are 5 squares in total 4 of side 1 and 1 of side 2
Logic I have used: 
if the current cell(i,j) is not 0, check for the min element in the left, right, diagonal element and add it to the value of current cell
else leave it as it is as there is no edge

After applying this logic matrix becomes
1 1
1 2
sumof all the elements in the matrix results in the total number of squares
*/

// int countSquares(vector<vector<int>>& matrix) {
// 	int m=matrix.size(),n=matrix[0].size();
// 	for(int i=1;i<m;i++){
// 		for(int j=1;j<n;j++){
// 			if(matrix[i][j]!=0) matrix[i][j]+=min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]});
// 		}
// 	}
// 	int cnt=0;
// 	for(int i=0;i<m;i++){
// 		for(int j=0;j<n;j++) cnt+=matrix[i][j];
// 	}
// 	return cnt;
// }
