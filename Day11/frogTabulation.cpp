#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;


int frogJump(vector<int> &heights,int k){
    int n = heights.size();
    vector<int> dp(n+1,-1);
    dp[0]=0;

    for(int i=1;i<n;i++){
        int res=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0) res = min(res,dp[i-j]+abs(heights[i]-heights[i-j]));
        }
        dp[i]=res;
    }

    return dp[n-1];

}

int main()
{

    vector<int> heights={10, 5, 20, 0, 15};
    int k=2;

    int result = frogJump(heights,k);

    cout<<"Result : "<<result<<endl;

    return 0;
}