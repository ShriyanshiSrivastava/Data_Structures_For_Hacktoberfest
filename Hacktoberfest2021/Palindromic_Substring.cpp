/* 
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

*/ 

#include<bits/stdc++.h>
#include<iostream>

using namspace std;

int countSubstrings(string s) {
        
        vector<string> ta;
        int n = s.size();
        if(n<=1)
        {
            if(n==1)
                return 1;
            return 0;
        }
        int dp[n][n];
        //substring of length 1
        for(int i = 0; i<n; i++)
        {
            dp[i][i] = 1;
            ta.push_back(s.substr(i, 1));
            
        }
        //substring of length 2
        for(int i = 0; i<n-1; i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1] = 1;
                ta.push_back(s.substr(i, 2));
            }
            
            else
                dp[i][i+1] = 0;
        }
        //substring of length greater than 2
        for(int i = 2; i<n; i++)
        {
            for(int j = 0, k = i; j<n-i, k<n; j++, k++)
            {
                if(s[j]==s[k])
                {
                    dp[j][k] = dp[j+1][k-1];
                    
                }
                else
                {
                    dp[j][k] = 0;
                }
                
                if(dp[j][k]==1)
                {
                    ta.push_back(s.substr(j, k-j+1));
                }
                
            }
        }
        
        return ta.size();
        
    }

int main()
{
    string s;
    cin>>s;
    
    cout<<"No. of palidromic strings : "<<countSubstrings(s);
}
