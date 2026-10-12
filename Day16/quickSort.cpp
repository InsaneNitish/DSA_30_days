#include <bits/stdc++.h>
using namespace std;


int partition(int low,int high,vector<int> &nums){
        int pivot = nums[(low + (high-low)/2)];
        int i = low;
        int j = high;

        while(true){
            while(nums[i]<pivot){
                i++;
            }
            while(nums[j]>pivot){
                j--;
            }
            
            if(i>=j) return j;
            swap(nums[i],nums[j]);
        }
    }


    void quickSortUtil(int low,int high, vector<int> &nums){
        if(low<high){
            int pivotIndex = partition(low,high,nums);
            quickSortUtil(low,pivotIndex-1,nums);
            quickSortUtil(pivotIndex+1,high,nums);
        }
    }


    vector<int> quickSort(vector<int>& nums) {
        quickSortUtil(0,nums.size()-1,nums);
        return nums;
    }


    int main(){
    vector<int> nums = {7, 4, 1, 5, 3};
    vector<int> result = quickSort(nums);

    for(auto it:result){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}