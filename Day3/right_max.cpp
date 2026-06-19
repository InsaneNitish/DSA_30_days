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
    for (int i = current - 1; i > 0; i--)
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

int trap(vector<int> &height)
{
    int total = 0;

    // go through each of the buiding (top of each)
    for (int building = 0; building < height.size(); building++)
    {

        // now for each building find it's right max and left max
        int r_max = rightMax(height, building);
        int l_max = leftMax(height, building);
        if (r_max == -1 || l_max == -1)
        {
            continue;
        }
        else
        {
            int min_h = min(height[r_max], height[l_max]);
            cout<<"min_h : "<<min_h<<endl;
            cout<<"building : "<<building<<endl;
            cout<<"height : "<<height[building]<<endl;
            total += min_h-height[building];
            cout<<"CURRENT HOLD : "<< min_h-height[building]<<endl;
        }
        cout<<endl;
    }
    return total;
}

int main()
{
    vector<int> height = {4,2,0,3,2,5};
    int res = trap(height);

    cout << "Result : " << res << endl;

    return 0;
}