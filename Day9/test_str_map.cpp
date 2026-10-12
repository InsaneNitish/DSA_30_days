#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    // phase 1
    int left = 0;
    int tracker = 0;
    int longest_str = 0;
    unordered_map<char, int> frq;

    for (int right = 0; right < s.length(); right++)
    {
        cout<<endl;
        tracker++;
        frq[s[right]]++;

        for (auto item : frq)
        {
            cout << item.first << endl;
            cout << item.second << endl;
        }

        while (frq[s[right]] != 1)
        {
            tracker--;
            cout<<"Tracker value : "<<tracker;
            left++;
            frq[s[left]]--;
        }
        cout<<endl;

        longest_str = max(longest_str, tracker);
    }

    return longest_str;
}

int main()
{
    string str;
    cout << "enter a string : ";
    cin >> str;

    int result = lengthOfLongestSubstring(str);

    cout << "\nResult : " << result << endl;
    // cout<<str[2];
    // for(auto ch:str){
    //     cout<<ch<<endl;
    // }

    // unordered_map<char,int> frq;

    // cout<<"\nChecking for this : "<<frq[str[1]]<<endl;

    // for(int right=0;right<str.length();right++){
    //     frq[str[right]]++;
    //     }

    return 0;
}