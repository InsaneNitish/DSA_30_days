#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j;
        i=0;
        for (int j = 1; j < nums.size(); j++) {
            if(nums[i]==nums[j]){
               continue;
            }
            else{
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    
    int k = sol.removeDuplicates(nums);
    
    cout << "Number of unique elements: " << k << endl;
    cout << "Modified array: ";
    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}