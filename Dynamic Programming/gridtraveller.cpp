#include<bits/stdc++.h> 
using namespace std; 
void solve(); 

long long a[1000][1000];

//Time complexity -> O(m*n)

long long gridTrav(int n,int m)
{
	if(a[m][n]!=0)
		return a[m][n];
	if(n==0 || m==0)
		return 0;
	if(n==1 && m==1)
		return 1;
	
	a[m][n] = gridTrav(m-1,n) + gridTrav(m,n-1);
	return a[m][n];
}


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
	cout<<gridTrav(5,6)<<endl;

	cout<<gridTrav(18,18);
	
} 