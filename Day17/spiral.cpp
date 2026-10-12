#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int tl = 0;
    int bl = 0;
    int tr = matrix[0].size() - 1;
    int br = matrix.size() - 1;

    int i = 0;
    int j = 0;

    int row = matrix.size();
    int col = matrix[0].size();

    int total = row * col;
    int index = 0;
    vector<int> result;
    bool flag = 0; // 0 for row and 1 for col

    while (index < total)
    {
        if (i == tl)
        {
            result.push_back(matrix[i][j]);
            tl++;
            j++;
            flag = !flag;
        }
        else if (j == tr)
        {
            result.push_back(matrix[i][j]);
            tr--;
            i++;
            flag = !flag;
        }
        else if (i == br)
        {
            result.push_back(matrix[i][j]);
            br--;
            j--;
            flag = !flag;
        }
        else if (j == bl)
        {
            result.push_back(matrix[i][j]);
            bl++;
            i--;
            flag = !flag;
        }
        else
        {
            result.push_back(matrix[i][j]);
            if (flag == 1)
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        index++;
    }
    return result;
}


int main(){

    ma[[1,2,3],[4,5,6],[7,8,9]]

    return 0;
}
