#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            if (nums[i] + nums[left] + nums[right] == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
            }
            else if (nums[i] + nums[left] + nums[right] > 0)
            {
                if (nums[left] > nums[right])
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
            else
            {
                if (nums[left] > nums[right])
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {1,2,0,1,0,0,0,0};
    vector<vector<int>> res = threeSum(nums);

    for (auto item : res)
    {
        for (auto i : item)
        {
            cout << i<<" ";
        }
        cout << endl;
    }

    return 0;
}