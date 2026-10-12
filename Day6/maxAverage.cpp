#include <iostream>
#include <vector>

using namespace std;

double findMaxAverage2(vector<int> &nums, int k)
{
    double sum = 0.0;

    for (int start = 0; start < k; start++)
    {
        sum += nums[start];
        cout << nums[start] << ",";
    }
    cout<<endl;
    cout << "Sum of initial k : " << sum << endl;

    double max_avg = sum / k;
    cout << "Avg of initial k : " << max_avg << endl;
    cout<<endl;



    for (int i = 1; i < (nums.size() - k + 1); i++)
    {
        sum = sum - nums[i - 1] + nums[i + k - 1];
        double new_avg = sum / k;
        cout<<"nums["<<i-1<<"] = "<<nums[i-1]<<endl;
        cout<<"nums["<<i+k<<"] = "<<nums[i+k]<<endl;
        cout << "Sum at each iteration "<<i<<" : " << sum << endl;
        cout << "Avg at each iteration "<<i<<" : " << new_avg << endl;
        cout << endl;

        if (new_avg > max_avg)
        {
            max_avg = new_avg;
        }
    }
    return max_avg;
}

double findMaxAverage(vector<int> &nums, int k)
{
    double max_avg = 0;

    for (int i = 0; i < (nums.size() - k + 1); i++)
    {
        double sum = 0;
        for (int start = i; start < k + i; start++)
        {
            sum += nums[start];
            cout << nums[start] << ",";
        }
        cout << endl;
        double new_avg = sum / k;
        cout << "Sum at each iteration : " << sum << endl;
        cout << "Avg at each iteration : " << new_avg << endl;
        cout << endl;
        if (new_avg > max_avg)
        {
            max_avg = new_avg;
        }
    }
    return max_avg;
}

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double res = findMaxAverage2(nums, k);

    cout << "Result : " << res << endl;

    return 0;
}