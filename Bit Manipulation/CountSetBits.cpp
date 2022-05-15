//  https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1#
// https://www.youtube.com/watch?v=g6OxU-hRGtY


class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits1(int n)   // Gives TLE
    {
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            int k = i;
            while(k != 0) {
                sum += k & 1;
                k = k >> 1;
            }
        }
        return sum;
    }
    int countSetBits(int n) {
        if(n == 0) return 0;
        int x = largestPowOf2(n);
        
        int a = x * (1 << (x - 1));
        int b = n - (1 << x) + 1;
        int c = n - (1 << x);
        int ans = a + b + countSetBits(c);
        return ans;
    }
    int largestPowOf2(int n) {
        int x = 0;
        
        while((1 << x) <= n) 
            x++;
        
        return x - 1;
    }
};
