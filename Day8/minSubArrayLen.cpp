#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:

    void display(vector <int> nums,int left,int right){
        while(left<right){
            cout<<nums[left]<<",";
            left++;
        }
        cout<<endl;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        //phase 1 initialization
        int left=0;
        //delta tracker
        int sum_tracker=0;
        //final result
        int min_len=INT_MAX;


        for(int right=0;right<nums.size();right++){
            //phase 2 expansion 
            sum_tracker+=nums[right];
            this->display(nums,left,right);

            //phase 3 checker for invalid condition
            while(sum_tracker-nums[left] > target){
                sum_tracker-=nums[left];
                left++;
            }

            //phase 4 where wwe update our final result
            if(sum_tracker>=target){
                min_len=min(min_len,right-left+1);
            }
        }

        if(min_len==INT_MAX){
            return 0;
        }

        return min_len;

        
    }
};


int main(){

    Solution s1;

    vector<int> nums = {1,2,3,4,5};
    int target = 11;

    int result = s1.minSubArrayLen(target,nums);

    cout<<"Result : "<<result<<endl;

    return 0;
}