//********In this ques we are finding out the top  K most frequqnted elements in our array*******
#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int,int>mp;
    int arr[]={1,1,1,3,4,2,2};// INPUT
    int n= sizeof(arr)/sizeof(arr[0]);
    int k=2;

    //OUTPUT:-
    // 1,2{because we can see here that 1 ahs a frequency of 3 and 2 has a frequency of 2}
    // and the value of our K is 2 hence the top 2 frequented elements present in a array are [1,2]
    

    for(int i=0;i<n;i++)  //finding frequency of each element using unordered map
    {
        mp[arr[i]]++;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;  // creating a min heap;

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        minh.push({it->second,it->first});  // here we are pushing the frequency of each element along with there no

        if(minh.size()>k)        // we will pop out the elements from the heap if it increases our desired size K
        {
            minh.pop();

        }
    }

    while(minh.size()>0)
    {
        cout<<minh.top().second<<" ";  //printing of all top K elements present in our array.
        minh.pop();
    }
}
