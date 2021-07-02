//https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/

// Memoization 

#include<bits/stdc++.h>
using namespace std;

#define NIL -1
#define MAX 100
int dp[MAX];

void initialize()
{
	int i;
	for( i =0 ; i < MAX ; i++)
	    dp[i] = NIL;
}

int fib(int n)
{
	if(dp[n] == NIL)
	 {
		if(n<=1)
		  dp[n] = n;
		else
           	 dp[n] = fib(n-1) + fib(n-2);
	}
	return dp[n];
}


int main()
{
	int n;	
	cin >>  n;
	initialize();
	cout << "Fibonacci number is " << fib(n)<<endl;
	return 0;
}
