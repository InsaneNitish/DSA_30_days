#include <iostream>
#include <map>

using namespace std;


int main(){

    map<int,int> mp;

    mp[1]=2;
    mp[3]=9;
    mp[2]=4;

    cout<<"Value at key is : "<<mp[3]<<endl;

    cout<<"Map contents : "<<endl;
    for(auto it:mp){
        cout<<it.first<<" -> "<<it.second<<endl;
    }

    return 0;

}