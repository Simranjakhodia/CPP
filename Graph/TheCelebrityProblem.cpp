//  https://leetcode.com/problems/find-the-celebrity/
// https://www.geeksforgeeks.org/the-celebrity-problem/


/* BRUTE FORCE TC : O(N ^ 2) SC : O (N) */

#include <bits/stdc++.h>
using namespace std;

bool matrix[4][4] = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0}
    
};

bool knows(int a, int b) {
    return matrix[a][b];
}

int findCelebrity2(int n) {
    int indegree[n]  = {0}, outdegree[n] = {0};
    
    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < n; j++) {
            int x = knows(i, j);
            outdegree[i] += x;
            indegree[j] += x;
        }
    } 
    for(int i = 0; i < n; i++)
        if(indegree[i] == n-1 && outdegree[i] == 0)
            return i;
    return -1;        
}    

int main() {
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" : cout << "Celebrity id : " << id;
    return 0;
}

/* Using Stack TC : O(N) SC: O(N)  */

int findCelebrity(int n) {
    stack <int> s;
    for(int i = 0; i < n; i++) 
        s.push(i);
    while(s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(knows(a, b))
            s.push(b);
        else 
            s.push(a);
    }    
    if(s.empty())
        return -1;
    int c = s.top();
    s.pop();
    
    for(int i = 0 ; i < n ; i++) {
        if(i != c && (knows(c, i) || !knows(i, c)))
            return -1;
    }
    return c;
} 

/* Using pointers TC : O(N) SC: O(1) */ 

int findCelebrity(int n) {
    int i = 0, j = n - 1;
    while(i < j) {
        if (matrix[j][i] == 1) // j knows i
            j--;
        else 
            i++;
    }
    
    int candidate = i;
    
    for(int i = 0; i < n; i++) {
        if(i != candidate) {
            if(matrix[i][candidate] == 0 || matrix[candidate][i] == 1)
                return -1;
        }
    }
    return candidate;
}
