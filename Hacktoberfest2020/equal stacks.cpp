// Find the maximum possible height of the stacks such that all of the stacks are exactly the same height.

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main() {
int a,b,c,i;
cin>>a>>b>>c;
int d[a],e[b],f[c];
long long int x=0,y=0,z=0;
for(i=0;i<a;i++)
    {       cin>>d[i];
    x=x+d[i];   }

for(i=0;i<b;i++)
   { cin>>e[i];
    y=y+e[i]; }
for(i=0;i<c;i++)
    { cin>>f[i];
    z=z+f[i]; }
int p=0,q=0,r=0; 
     while(x!=y ||y!=z ||x!=z) 
    {
    if(x>y && x>z|| x==y && x>z || x==z &&x>y)
      x=x-d[p++];
     else if(y>x && y>z|| y==x && y>z || y==z &&y>x)
            y=y-e[q++];
     else if(z>x &&z>y || z==y && z>x || z==x &&z>y)
            z=z-f[r++];
  } 
        cout<<x;
   return 0;
}
