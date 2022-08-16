// https://www.interviewbit.com/problems/valid-ip-addresses/



bool isValid(string str) {
    if(str.length() == 1 && str[0] == '0') return true;
    if(str[0] == '0' || str.length() > 3) return false;
    int k = stoi(str);
    if(k >= 0 && k <= 255)
        return true;
    return false;
}

void solve(vector<string>& ans, int idx, string temp, string A, int n, int cnt) {
    if(cnt > 4) return;
    if(idx == n && cnt == 4) {
        temp.pop_back();
        ans.push_back(temp);
        return;
    }
    string str = temp;
    for(int i = idx; i < min(idx + 3, n); i++) {
        string curr = A.substr(idx, i - idx + 1);
        if(isValid(curr)) {
            str += curr + '.';
            solve(ans, i + 1, str, A, n, cnt + 1);
            str = temp;
        }
        else 
            break;
    }
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    int n = A.length();

    solve(ans, 0, "", A, A.length(), 0);
    return ans;
}


