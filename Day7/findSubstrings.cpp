#include <iostream>
#include <vector>
#include <string>


using namespace std;


void findSubstr(string &word, int k){

    int word_size = word.length();
    for(int i=0;i<(word_size-k+1);i++){
        string substr;
        for(int j=i;j<k+i;j++){
            substr+=word[j];
        }
        cout<<"Substring No. "<<i<<" : "<<substr<<endl;
    }
}

int main(){

    string word = "abcd";
    findSubstr(word,2);

    return 0;
}