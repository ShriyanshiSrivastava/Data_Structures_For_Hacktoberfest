// Length of longest common subsequence in two strings
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cout << "Enter string 1" << endl;
    cin >> s1;
    cout << "Enter string 2" << endl;
    cin >> s2;
    int m = s1.length();
    int n = s2.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}