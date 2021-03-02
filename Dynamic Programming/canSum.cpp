#include<bits/stdc++.h> 
using namespace std; 

int memo[1000000]={0};

int canSum(int targetSum, int a[],int n)
{
	if(memo[targetSum]!=0) return memo[targetSum];
	if(targetSum == 0) return 1;
	if(targetSum < 0) return -1;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		int remainder = targetSum - a[i];
		if(canSum(remainder,a,n) == 1)
		{
			memo[targetSum] = 1;
			return 1;
		}
		
	}
	memo[targetSum] = -1;
	return -1;
}

void solve(); 
int main() 
{ 
   ios_base::sync_with_stdio(false);cin.tie(NULL); 
   
   #ifndef ONLINE_JUDGE 
   freopen("input1.txt", "r", stdin); 
   freopen("error1.txt", "w", stderr); 
   freopen("output1.txt", "w", stdout); 
   #endif 
   
   int t=1; 
   cin>>t; 
   while(t--) 
   { 
      solve(); 
      cout<<"\n"; 
   } 
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
} 
void solve() 
{ 
	int a[] = {3,10,2};
	if(canSum(1,a,3)==1)
		cout<<"YES";
	else
		cout<<"No";
} 