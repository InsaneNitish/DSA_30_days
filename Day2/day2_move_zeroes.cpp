#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        if(nums.size()==1){
            return;
        }

        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]==0 && nums[j]==0){
                continue;
            }
            else if(nums[i]==0){
                nums[i]=nums[j];
                nums[j]=0;
                i++;
            }
            else{
                i++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    
    sol.moveZeroes(nums);
    
    cout << "Modified array: ";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}