/*

Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.


*/

int numberOfSteps(int num) {
        
        if(num==0)
        {
            return 0;
        }
        
        int set = __builtin_popcount(num);
        int tot = (int)log2(num)+1;
        int unset = tot - set;
        
        int ans = 2*(set-1) + unset + 1;
        return ans;
        
    }
    
    
int main()
{
  int num;
  cin>>num;
  cout<<"Number of operations required = "<<numberOfSteps(num);
  return 0;

}
