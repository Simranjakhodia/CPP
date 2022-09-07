//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    
    int helper(Node* root, int &re) {
        if(!root)
            return 0;
        
        int l = helper(root->left, re);
        int r = helper(root->right, re);
        
        if(!root->left && !root->right) 
            return root->data;
        
        if(!root->left)
            return root->data + r;
        
        if(!root->right)
            return root->data + l;
        
        re = max(re, l + r + root->data);
        return root->data += max(l, r);
    }
    int maxPathSum(Node* root)
    {
        int re = INT_MIN;
        int ans = helper(root, re);
        if(!root->left || !root->right)
            re = max(ans, re);
        return re;
    }
};


/*

the solution for this test case is 16 
5 N 6 -5 5

coz:
In this particular test case, root is also a “leaf”. In the problem description
“leaf” is mentioned as a node which is only connected to one node and root is only
connected to one node (6) in this case.

[so..  
 if(!root->left or !root->right)
           re = max(re, ans);
code lines added in maxPathSum function]

the actual answer should be 6 coz
leaf node is that node that has zero child
but  the root itself has one child in this case 
*/

https://practice.geeksforgeeks.org/problems/maximum-path-sum/1
https://leetcode.com/problems/binary-tree-maximum-path-sum/
https://leetcode.com/problems/binary-tree-maximum-path-sum/
https://leetcode.com/problems/path-sum/
https://leetcode.com/problems/path-sum-ii/

