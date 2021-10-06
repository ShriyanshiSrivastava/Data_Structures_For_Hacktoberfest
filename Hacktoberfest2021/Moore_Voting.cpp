#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int a[])
{
    int candidate = a[0];
    int count = 1;
    for (int i = 1; i < 9; i++)
    {
        if (a[i] == candidate)
        {
            count++;
        }
        else
        {
            if (count == 1)
            {
                candidate = a[i];
            }
            else
            {
                count--;
            }
        }
    }
    return candidate;
}

int main()
{
    int a[] = {1, 2, 2, 3, 2, 3, 4, 2, 2};
    cout << findMajorityElement(a);
    return 0;
}