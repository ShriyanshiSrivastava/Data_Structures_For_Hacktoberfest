//https://leetcode.com/problems/sort-the-matrix-diagonally/
class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int x, y, counter;
        for (int i = 1; i <= m; i++)
        {
            vector<int> val;
            x = i;
            y = 0;
            while (x < m && y < n)
            {
                val.push_back(mat[y][x]);
                x++;
                y++;
            }
            sort(val.begin(), val.end());
            x = i;
            y = 0;
            counter = 0;
            while (x < m && y < n)
            {
                mat[y][x] = val[counter];
                counter++;
                x++;
                y++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            vector<int> val;
            x = 0;
            y = i;
            while (x < m && y < n)
            {
                val.push_back(mat[y][x]);
                x++;
                y++;
            }
            sort(val.begin(), val.end());
            x = 0;
            y = i;
            counter = 0;
            while (x < m && y < n)
            {
                mat[y][x] = val[counter];
                counter++;
                x++;
                y++;
            }
        }
        return mat;
    }
};
