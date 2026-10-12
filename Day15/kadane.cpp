#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int kadane(vector<int> &nums){
        int sum = 0; 
        int maxSum = INT_MIN;
        int start= 0;
        int actual_s = 0;
        int end =0;
        for(int i = 0;i< nums.size();i++){
            if(sum==0) start=i;
            sum+=nums[i];
            if(maxSum<sum){
                maxSum= sum;
                end = i;
                actual_s=start;
            } 
            if(sum<0) sum=0;
        }
        //let us print the vector array
        for(int i=actual_s;i<=end;i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        return maxSum;
}

int main(){
    vector<int> nums = {-2, -3, 4, -1, 0, 5};
    cout<<"Result : " << kadane(nums)<<endl;
    return 0;
}