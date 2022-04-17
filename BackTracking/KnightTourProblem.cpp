// https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/


#include<bits/stdc++.h>
using namespace std;
#define n 8 
void printSol(int sol[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
        cout << setw(2) << sol[i][j] <<"  ";
        cout << endl;
    }
}

int isSafe(int x, int y, int sol[n][n]) {
    return (x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1);
}
int solveKTUtil(int x, int y, int sol[n][n], int moves, int xMov[n], int yMov[n]) {
    int k, next_x, next_y;
    
    if(moves == n*n) {
        return 1;
    }
    
    for(int k = 0; k < 8; k++) {
        next_x = x + xMov[k];
        next_y = y + yMov[k];
        if(isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = moves;
            
            if(solveKTUtil(next_x, next_y, sol, moves + 1, xMov, yMov) == 1)
                return 1;
            else 
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

int solveKT() {
    int sol[n][n];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            sol[i][j] = -1;
    
    int xMov[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMov[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    sol[0][0] = 0;
    
    if(solveKTUtil(0, 0, sol, 1, xMov, yMov) == 0) {
        cout << "Solution doesnt exist\n";
        return 0;
    }    
    else 
        printSol(sol);
    
    return 1;
}



int main() {
    solveKT();
    return 0;
}
