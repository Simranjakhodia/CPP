// https://leetcode.com/problems/online-stock-span/


class StockSpanner {
public:
    stack<pair<int, int>> s;
    int count ;
    StockSpanner() {
        s.push({INT_MAX, -1});
        count = 0;
    }
    int next(int price) {

         while(!s.empty() && s.top().first <= price) {
              s.pop();
            }  
         int res = count - s.top().second;
          
         s.push({price, count++});
         return res;
          
     }    
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
