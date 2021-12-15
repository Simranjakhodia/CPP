// https://www.geeksforgeeks.org/stdunique-in-cpp/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
    vector<int> v = { 1, 2, 3, 3, 3, 10, 1, 2, 3, 7, 7, 8};
    vector<int>:: iterator ip;
    
    // sorting the array
    sort(v.begin(), v.end());
    // // Now v becomes 1 1 2 2 3 3 3 3 7 7 8 10
  
    ip = unique(v.begin(), v.begin() + 12);
    // Now v becomes {1 2 3 7 8 10 * * * * * *}
  
    v.resize(distance(v.begin(), ip));
  
    for(ip = v.begin(); ip != v.end(); ip++) {
        cout << *ip << " ";
    }
    return 0;
}
