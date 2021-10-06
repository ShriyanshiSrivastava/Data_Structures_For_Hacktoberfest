//Given an integer numRows, return the first numRows of Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;
    for (auto i = 0; i < numRows; ++i)
    {
        result.push_back(vector<int>(i + 1, 1));
        for (auto j = 1; j < i; ++j)
        {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }
    return result;
}

int main()
{
    int numRows;
    cout << "Enter number of Rows of Pascal Triangle: ";
    cin >> numRows;

    vector<vector<int>> result = generate(numRows);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
