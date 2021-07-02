//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/


//Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

//USING BRUTE-FORCE ALGO OR EXHAUSTIVE SEARCH

#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){return (a > b) ? a : b;}

int knapsack(int W , int wt[], int val[] , int n)
{
	if (n == 0 || W == 0)
	   return 0;
	if (wt[n-1] > W)
	   return knapsack(W , wt , val , n-1);
	else
	   return max( val[n-1] + knapsack(W -wt[n-1] , wt , val , n-1), knapsack(W , wt , val , 		  n-1 ));

}

int main()
{
	int val[] = { 60 , 100 ,120 }; 
	int wt[] = { 10 , 20 ,30 );
	int W = 50 ;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapsack(W , wt , val , n);
	return 0;

}
