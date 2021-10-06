#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{	string s;
	cin>>s;
	s += "$";//adding a special character to make a substring look different than the corresponding others
			/// the order of the strings has not changed, because $ is smaller than all characters
			///assume the string is in cyclic order
	int n = s.size();
	vector<int> p(n),//for Positions of the strings
				c(n);//for equivalence Classes
				
	{	
		//K==0
		vector<pair<char, int> > a(n);//we need to sort the single character of string
										///the strings should be sorted from the first characters onwards
		for(int i=0; i<n; i++){///adding characters of string in a vector with corresponding indices
			a[i] = {s[i], i};
			}
		sort(begin(a), end(a));//sorting the strings lexicographically
								///O(nlogn)
		for(int i=0; i<n ;i++) p[i] = a[i].second;//stored sorted positions in position array
		
		c[p[0]] = 0;//making the first class as zero for character at a[0].first
					///making equivalence classes for k = 0
		for(int i=1; i<n; i++){
			if(a[i].first == a[i-1].first){///if the characters are same, 
				c[p[i]] = c[p[i-1]];///we assign the same class
				}
			else{
				c[p[i]] = c[p[i-1]] + 1;///otherwise class is incremented by 1
				}
			}
	}
	
	int k = 0;
	while((1<<k) < n){///(1 * pow(2, k)) < n
		//k->k+1 transition
		vector<pair<pair<int, int>, int>> a(n);///first pair is for left and right equivalence classes
												///second integer is for string indices
		for(int i=0; i<n; i++){
			a[i] = {{c[i],c[i+(1<<k)%n]}, i};///i and (i+(1<<k)%n) are left and right halves of string for a given k,
											///%n is for cyclic computation
			}
		sort(begin(a), end(a));
		
		for(int i=0; i<n ;i++) p[i] = a[i].second;//stored sorted positions in position array
													///updating the position array
		
		c[p[0]] = 0;//making the first class as zero for substring at a[0].first
					///making equivalence classes for k = 1 & so on till ((1<<k) < n)
		for(int i=1; i<n; i++){
			if(a[i].first == a[i-1].first){///if the substrings are same, 
				c[p[i]] = c[p[i-1]];///we assign the same class
				}
			else{
				c[p[i]] = c[p[i-1]] + 1;///otherwise class is incremented by 1
				}
			}
			k++;
		}
	
	for(int i=0; i<n; i++){
		//cout<<p[i]<<" "<<s.substr(p[i], n-p[i])<<"\n";
		cout<<p[i]<<" ";
		}
	return 0;
}
