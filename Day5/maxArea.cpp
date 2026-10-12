#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;

    int area = 0;

    while (left < right)
    {
        int breadth;
        int length = right - left;

        if (height[left] > height[right])
        {
            breadth = height[right];
            right--;
        }
        else
        {
            breadth = height[left];
            left++;
        }

        int newArea = length * breadth;

        cout << "left = " << left << endl;
        cout << "right = " << right << endl;
        cout << "Length = " << length << endl;
        cout << "Breadth = " << breadth << endl;
        cout << "Area = " << area << endl;

        if (area < newArea)
        {
            area = newArea;
        }

        cout << "Updated Area = " << area << endl;
        cout << endl;
    }
    

    return area;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(height);

    cout << "Result Area : " << result;
}
