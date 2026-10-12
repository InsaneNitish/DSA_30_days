#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int frogJump(int n, vector<int> &heights,vector<int> &dp){
    if(n<=0) return 0;
    if(dp[n]!=-1) return dp[n];

    int left = frogJump(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
    int right = INT32_MAX;
    if(n>1) right = frogJump(n-2,heights,dp)+abs(heights[n]-heights[n-2]);

    return dp[n]=min(left,right);
}

int main(){
    int n=6;
    vector<int> heights={30,10,60,10,60,50};
    vector<int> dp(n+1,-1);
    int result = frogJump(n,heights,dp);

    cout<<"Result : "<<result<<endl;
    return 0;
}