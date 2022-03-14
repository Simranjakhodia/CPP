#include<bits/stdc++.h>
using namespace std;

void sortK(int arr[], int n, int k) {
    int size = (n == k) ? k : k + 1;
    priority_queue<int, vector<int>, greater<int>> pq (arr, arr + size);  // minHeap
    int idx = 0;
    for(int i = k + 1; i < n; i++) {
        arr[idx++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    
    while(!pq.empty()) {
        arr[idx++] = pq.top();
        pq.pop();
    }
    k = 7;
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;    
}

int main() {
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int k = 3;
    sortK(arr, n, k);
    cout << "Sorted array is :" << endl;
    printArray(arr, n);
    return 0;
}

// https://www.geeksforgeeks.org/nearly-sorted-algorithm/

// https://www.youtube.com/watch?v=4BfL2Hjvh8g&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=2
