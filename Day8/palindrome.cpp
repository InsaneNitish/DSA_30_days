#include <iostream>
#include <string>

using namespace std;

int main(){

    int num;
    cout<<"enter a number : ";
    cin>>num;
    string st_num = to_string(num);

    cout<<st_num[2];
    for(auto ch:st_num){
        cout<<ch<<endl;
    }
    




    return 0;
}