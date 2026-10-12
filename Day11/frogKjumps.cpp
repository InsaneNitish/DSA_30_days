#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

        int f(int n,vector<int> &heights,int k,vector<int> &dp){
        if(n==0) return 0;

        if(dp[n]!=-1) return dp[n];
        int res= INT_MAX;
        for(int i=1;i<=k;i++){
            if(n-i >=0){
                res = min(res, f(n-i,heights,k,dp) +abs(heights[n]-heights[n-i]));
            }
        }
        cout<<"Result and N  : "<<res<< ","<<n<<endl;

        return dp[n]= res;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n+1,-1);
        return f(n-1,heights,k,dp);
    }

int main()
{

    vector<int> heights={10, 5, 20, 0, 15};
    int k=2;

    int result = frogJump(heights,k);

    cout<<"Result : "<<result<<endl;

    return 0;
}