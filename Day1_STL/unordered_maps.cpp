#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){

    vector <int> nums = {32,1,2,3,4,5,6,1,4,2,3,4,1};

    unordered_map<int,int> frequency;

    for(int num:nums){
        frequency[num]++;
    }

    cout<<"Frequency map  : \n";

    //adding manually a key pair
    frequency[76] = 2;

    auto iter = frequency.find(76);

    if(iter!=frequency.end()){
        cout<<"Key : "<<iter->first<<endl;
        cout<<"Value : "<<iter->second<<endl;
    }

    frequency.erase(76);

    if(iter!=frequency.end()){
        cout<<"Key : "<<iter->first<<endl;
        cout<<"Value : "<<iter->second<<endl;
    }else{
        cout<<"not Found any key 76\n";
    }

    for(auto item: frequency){
        cout<<item.first<<" --> "<<item.second<<endl;
    }



    return 0;
}