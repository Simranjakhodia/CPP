// https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/


class Solution{
  public:
    
    string multiplyStrings(string s1, string s2) {
        
       int sign = 1;
       string num1 = s1, num2 = s2;
       if(num1[0] == '-' && num2[0] != '-')
        num1 = num1.substr(1), sign = -1;
        
        else if(num1[0] != '-' && num2[0] == '-') 
        num2 = num2.substr(1), sign = -1;
    
        else if(num1[0] == '-' && num2[0] == '-') {
            num1 = num1.substr(1);
            num2 = num2.substr(1);
        }
        
        s1 = num1, s2 = num2;
        int len1 = s1.length(), len2 = s2.length();
        vector<int> res(len1 + len2, 0);
    
        int idx1 = 0, idx2 = 0;
    
        for(int i = len1 - 1; i >= 0; i--) {
            int carry = 0;
            int n1 = num1[i] - '0';
            
            idx2 = 0;
            
            for(int j = len2 - 1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                int sum = n1*n2 + res[idx1+idx2] + carry;
                carry = sum / 10;
                res[idx1 + idx2] = sum % 10;
                idx2++;
            }
        
            if(carry > 0)
                res[idx1 + idx2] += carry;
                
            idx1++;
        }
    
        int i = res.size() - 1;
        while(i >= 0 && res[i] == 0) 
            i--;
            
        if(i == -1)
            return "0";
            
            
        string s = "";
        if(sign == -1)
            s += '-';
        while(i >= 0)
            s += to_string(res[i--]);
            
        return s;
        
        }

};
