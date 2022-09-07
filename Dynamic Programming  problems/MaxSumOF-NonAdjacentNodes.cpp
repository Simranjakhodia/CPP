//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}



// } Driver Code Ends
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
/*


lets understand the question from a beginner's pov→

see example2   

roughly it looks like→

                     1

           2               3

  4                    5       6 

 

TWO CASES→

INCLUDE→if i pick 1(include 1) ,i CANNOT pick its children 2,3  .but i can pick 4 ,5,6
EXCLUDE →if i exclude 1, i can pick its children 2,3 ,but i CANNOT pick 2,3's children→i.e 4,5,6
now i want to get the max sum, so i'll return maximum of case1 ,case2

 

recursive approach→(gives TLE  ,but it helps us to know why we need to use dp for this question)

*/
class Solution1{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
       if(!root) return 0;
       
       int inc = root->data;
       if(root->left){
           inc += getMaxSum(root->left->left);
           inc += getMaxSum(root->left->right);
       }
       if(root->right){
           inc += getMaxSum(root->right->left);
           inc += getMaxSum(root->right->right);
       }
       
       int exc = getMaxSum(root->left) + getMaxSum(root->right);
       
       return max(inc, exc);
    }
};

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*, int> mp;
    int getMaxSum(Node *root) 
    {
       if(!root) return 0;
       if(mp.find(root) != mp.end())
            return mp[root];
            
       int inc = root->data;
       if(root->left) {
           inc += getMaxSum(root->left->left);
           inc += getMaxSum(root->left->right);
       }
       if(root->right) {
           inc += getMaxSum(root->right->left);
           inc += getMaxSum(root->right->right);
       }
       
       int exc = getMaxSum(root->left) + getMaxSum(root->right);
       
       mp[root] = max(inc, exc);
       
       return mp[root];
    }
};



// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

