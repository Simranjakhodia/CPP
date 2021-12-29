// https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/discuss/1599341/Greedy

class Solution {
public:
    int minimumBuckets(string street) {
        for(int i = 0 ; i < street.length(); i++) {
            if (street[i] == 'H') {
                if(i > 0 && street[i-1] == 'B') 
                    continue;
                else if(i < street.length()-1 && street[i+1] == '.')
                    street[i+1] = 'B';
                else if (i > 0 && street[i-1] == '.')
                    street[i-1] = 'B';
                else 
                    return -1;
            }
        }
        return count(street.begin(), street.end(), 'B');
    }
};

// https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/discuss/1599341/Greedy
