//https://www.geeksforgeeks.org/unbounded-fractional-knapsack/
//Unbounded Fractional Knapsack

//Given weights and values of n items, the task is to put these items in a knapsack of capacity W to get the maximum total value in the knapsack, we can repeatedly put the same item and we can also put fraction of an item.


#include <bits/stdc++.h>
using namespace std ; 

float knapsack(int W ,float wt[], float val[],int n)
{

	float maxratio = INT_MIN;
	int maxindex = 0;
	for(int i=0 ; i<n ;i++)
	{
		if(( val[i]/wt[i]) > maxratio ) {
			maxratio = val[i] / wt[i] ;
			maxindex = i;
		}
	}
	return (W * maxratio);
}

int main()
{
	float val[] = {14,27,44,19};
	float wt[] = {6,7,9,8};
	int n = sizeof(val) / sizeof(val[0]);
	int W = 50;
	cout << knapsack(W,wt,val,n)<<endl;
	return 0;
}

