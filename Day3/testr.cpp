#include <iostream>
#include <vector>

using namespace std;

// this function will find out the right max if found return index of it otherwise will return -1
int rightMax(const vector<int> &height, int current)
{
    int r_max = height[current];
    int result;
    int exist=0;
    for (int i = current + 1; i < height.size(); i++)
    {
        if (height[i] > r_max)
        {
            r_max = height[i];
            result=i;
            exist=1;
        }
    }
    if(exist==1){
        return result;
    }else{
    return -1;
    }
}


// this function will find out the left max if found return index of it otherwise will return -1
int leftMax(const vector<int> &height, int current)
{
    int l_max = height[current];
    int result;
    int exist=0;
    for (int i = current - 1; i >= 0; i--)
    {
        if (height[i] > l_max)
        {
            l_max = height[i];
            result=i;
            exist=1;
        }
    }
    if(exist==1){
        return result;
    }else{
    return -1;
    }
}


int main()
{
    vector<int> height = {4,2,0,3,2,5};
    int res = rightMax(height,1);
    int les = leftMax(height,1);

    cout << "Result : " << res << endl;
    cout << "Result : " << les << endl;

    return 0;
}