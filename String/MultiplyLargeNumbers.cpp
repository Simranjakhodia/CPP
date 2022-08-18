//  https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/




#include<bits/stdc++.h>
using namespace std;

int main() {
    string num1 = "12354214154545454545444";
    string tempnum1 = num1;
    string num2 = "171454654654654654654544548544544544545";
    string tempnum2 = num2;
    
    if(num1[0] == '-' && num2[0] != '-')
        num1 = num1.substr(1);
        
    else if(num1[0] != '-' && num2[0] == '-') 
        num2 = num2.substr(1);
    
    else if(num1[0] == '-' && num2[0] == '-') {
        num1 = num1.substr(1);
        num2 = num2.substr(1);
    }
    string s1 = num1;
    string s2 = num2;
    
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
        
    if(i == -1){
        cout << "0" << endl;
        return 0;
    }
    string s = "";
    
    while(i >= 0)
        s += to_string(res[i--]);
        
    cout << s << endl;
    return 0;
    
}




