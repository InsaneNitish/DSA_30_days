#include <iostream>
#include <vector>
#include <climits>

using namespace std;
    int fun(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(row==0 && col==0) return grid[0][0];
        if(dp[row][col]!=-1) return dp[row][col];

        int up=INT_MAX,left=INT_MAX;
        if(row>0) up =  fun(row-1,col,grid,dp) + grid[row][col];
        if(col>0) left = fun(row,col-1,grid,dp) + grid[row][col];

        return dp[row][col]=min(up,left);

    }

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        int result =  fun(row-1,col-1,grid,dp);
        cout<<endl;
        cout<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return result;
    }

int main(){
    vector<vector<int>> grid={{1,3,1},{1,5,1},{4,2,1}};
    int result = minPathSum(grid);
    cout<<"\nResult : "<<result<<endl;
    return 0;
}