#include <iostream>
#include <vector>

using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int n,vector<int> &nums){
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(nums[j]<nums[j-1]){
                swap(&nums[j],&nums[j-1]);
            }
        }
    }
}

void display(const vector<int> nums){
    for(auto num:nums){
        cout<<num<<",";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cout<<"Enter arr["<<i<<"] = ";
        cin>>nums[i];
    }

    cout<<"Array Before Sorting  : ";
    display(nums);
    bubbleSort(n,nums);
    cout<<"Array After Sorting  : ";
    display(nums);

    return 0;
}