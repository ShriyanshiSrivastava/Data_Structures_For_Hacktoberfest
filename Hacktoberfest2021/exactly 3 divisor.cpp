#include<bits/stdc++.h>   //c++ program to print all number which has 3 divisor
#include<math.h>                          //the number itself, one, and the other divisor
                            // less than or equal to n using SIEVE OF ERATOSTHENES.
using namespace std;
//This function will generate all the prime number upto n and print their squares.
void exact3divisor(int n)
{
    bool prime[n+1];
    memset(prime,true,sizeof(prime)); //memset will set all values to true in the prime array.
    prime[0]=prime[1]=false;

    for(int p=2;p<=sqrt(n);p++) //if prime[p] is not changed then it is a prime.
        {
        if(prime[p]==true)
        {
            for(int i=p*p;i<=n;i=i+p)
            {
                prime[i]=false;
            }
        }
    }
    //print square of all prime number or the number which are marked true.
    cout<<"numbers with 3 divisor are: \n";
    for(int i=0;i*i<=n;i++)
       if (prime[i]==true)
            cout<<i*i<<" ";


}
//driver program
int main()
{ int t;
 cin>>t;
 while(t--)
 {   int n;
    cout<<"enter the number ";
    cin>>n;
    exact3divisor(n);

}
return 0;
}
