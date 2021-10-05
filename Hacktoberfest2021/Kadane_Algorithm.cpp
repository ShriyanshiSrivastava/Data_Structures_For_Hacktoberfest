// Kadane's Algorithm
#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int m = INT_MIN, q = 0;

	for (int i = 0; i < size; i++)
	{
		q = q + a[i];
		if (m < q){
			m = q;
    }

		if (q < 0){
			q = 0;
    }
	}
	return m;
}
int main()
{
	int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int max_sum = maxSubArraySum(a,n);
	cout << "Maximum Sum by Kadane's Algorithm is: " << max_sum;
	return 0;
}
