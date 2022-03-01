// https://www.interviewbit.com/problems/distribute-candy/


int Solution::candy(vector<int> &A) {
    
    int n = A.size();
    vector<int> v1(n, 1);
    vector<int> v2(n, 1);
    int res = 0;
    for(int i = 1; i < n; i++) {
        if(A[i] > A[i-1]) v1[i] = v1[i-1] + 1;
        else v1[i] = 1;
    }
    for(int i = n-2; i >= 0; i--) {
        if(A[i] > A[i+1]) v2[i] = v2[i+1] + 1;
    }
    for(int i = 0; i < n; i++) {
        res+= max(v1[i], v2[i]);
    }
    return res;
}
