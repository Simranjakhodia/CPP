// https://www.geeksforgeeks.org/solve-dynamic-programming-problem/

//Given 3 numbers {1, 3, 5}, we need to tell
//the total number of ways we can form a number 'N' 
//using the sum of the given three numbers.(allowing repetitions and different arrangements).

//Memoization/ Tabular dp approach

#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int dp[MAX];

void initialize()
{
	int i;
	for(i = 0 ;i < MAX ; i++ )
	 dp[i]= -1;
}

int funct(int n)
{
	if(n < 0 )
          return 0;
	if(n == 0)
	  return 1;
	
	if(dp[n] != -1)
	 return dp[n];
	return dp[n] = funct(n-1) + funct(n-3) + funct(n-5);

}
	
int main()
{
	int n;
	cin >> n;
	initialize();
	cout << "Total ways are : " << funct(n) << endl;
}

