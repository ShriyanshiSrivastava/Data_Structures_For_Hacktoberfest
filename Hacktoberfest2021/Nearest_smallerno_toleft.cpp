#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    stack<int>s;
    //INPUT
    int arr[]={2,7,4,8};
    int n =sizeof(arr)/sizeof(arr[0]);
    //OUTPUT
    // {-1,2,2,4}
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        {
            v.push_back(-1);
        }

        else if(!s.empty() && s.top()<arr[i])
        {
            v.push_back(s.top());
        }
        else if(!s.empty() && s.top()>=arr[i])
        {
            while(!s.empty() && s.top()>=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                s.pop();
            }
            else{
                v.push_back(s.top());
            }
        }

        s.push(arr[i]);
    }

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
