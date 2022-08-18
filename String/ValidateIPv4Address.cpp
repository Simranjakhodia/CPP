///   https://practice.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1


class Solution {
    public:
        int isValid(string s) {
            int i = 0, count = 0, n = s.size();
            while(i < n) {
                string tmp = "";
                while(i < n && s[i] != '.' && s[i] >= '0' && s[i] <= '9')
                    tmp+= s[i++];
                if(tmp.size() == 0 || tmp.size() > 3 || stoi(tmp) > 255 || stoi(tmp) < 0)
                    return 0;
                if(tmp.size() >= 2 && tmp[0] == '0')
                    return 0;
                if(s[i] == '.')
                    count++;
                i++;
            }
            if(count < 3 || count > 3) 
                return 0;
                
            return 1;
        }
};
