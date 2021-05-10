

//Find the Nth number of the series. The nth number of geek-onacci series is a sum of the last three numbers (summation of N-1th, N-2th, and N-3th geek-onacci numbers)
//https://practice.geeksforgeeks.org/problems/geek-onacci-number/0/?category[]=Recursion&category[]=Recursion&page=1&query=category[]Recursionpage1category[]Recursion






#include<iostream>

using namespace std;

int main()
{
    int t,m,n,s=0;
    cout >>t;
    vector<int>a(3);
    for(int i=1 ; i<=t ;i++)
    {
      for(int j=1 ; j<=3;j++)
        {   
            cout >>m;
            a.push_back(m);
        }
        cout>>n;
        s = funct(a,n);
        cout<< s <<endl;
        
    }
    return 0;
    
}

int funct(int a[] , int n)
{   static k=3;
    if(k == n)
    return a[(n-1)%3];
    else
    {
        a[k%3] = a[(k-1)%3] + a[(k-2)%3] + a[(k-3)%3] ;
        k++;
        return funct(a,n);
    }
}
