//Generate parenthesis

/*Input:
N = 3
Output:
((()))
(()())
(())()
()(())
()()()
*/

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses

//Backtracking Approach Used
class Solution
{   
    void funct(vector<string> &k , string m , int o , int c ,int n)
    {
       if(c == n)
          {
              k.emplace_back(m);
              return;
          }
      else 
       {
           if (o < n)
                {   
                    m = m + '(';
                    funct( k , m , o+1 , c , n);
                    m.pop_back();
                }
           if( c < o)
               {
                 m = m + ')';
                 funct( k , m , o , c+1 , n);
                // m.erase(m.length()-1);
                 m.pop_back();
               }
       }
       
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        
        vector<string> k ;
        
            if(n>0)
            funct( k , "" , 0 , 0 , n) ; 
           
        return k;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
