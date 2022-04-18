// https://leetcode.com/problems/shopping-offers


class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int bestPrice = calculateWOffers(price, needs);
        for(auto &sp : special) {
            subtractOffer(sp, needs);
            if(noNeg(needs)) {
                int withOffer = sp.back() + shoppingOffers(price, special, needs);
                bestPrice = min(bestPrice, withOffer);
            }
            addOffer(sp, needs);
        }
        return bestPrice;
    }
    int calculateWOffers(vector<int>& price, vector<int>& needs) {
        int res = 0;
        for(int i = 0; i < price.size(); i++) 
            res += price[i] * needs[i];
        
        return res;
    }
    void subtractOffer(vector<int>& sp, vector<int>& needs) {
        for(int i = 0; i < needs.size(); i++) 
            needs[i] -= sp[i];
    }
    
    void addOffer(vector<int>& sp, vector<int>& needs) {
        for(int i = 0; i < needs.size(); i++)
            needs[i] += sp[i];
    }
    bool noNeg(vector<int> needs){
        for(auto n : needs)
            if(n < 0) return false;
        return true;
    }
};

// https://leetcode.com/problems/shopping-offers/discuss/992433/C%2B%2B-or-Recursion-or-Clean-code
