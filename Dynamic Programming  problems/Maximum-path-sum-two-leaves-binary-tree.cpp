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

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


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

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}
// } Driver Code Ends
