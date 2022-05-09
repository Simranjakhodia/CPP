// https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#


#include<map>
class Solution{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length() != str2.length()) return false;
        map<char, char> mp1, mp2;
        for(int i = 0; i < str1.length(); i++) {
            if(mp1.find(str1[i]) == mp1.end() && mp2.find(str2[i]) == mp2.end()){
                mp1[str1[i]] = str2[i];
                mp2[str2[i]] = str1[i];
            }    
            else if(mp1.find(str1[i]) == mp1.end() || mp2.find(str2[i]) == mp2.end())
                    return false;
            else {
                if(mp1[str1[i]] == str2[i] && mp2[str2[i]] == str1[i])
                    continue;
                else return false;
            }
        }
        return true;
    } 
    
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length() != str2.length()) return false;
        map<char, char> mp1, mp2;
        int c = 0;
        for(int i = 0; i < str1.length(); i++) {
            if(mp1.find(str1[i]) == mp1.end() && mp2.find(str2[i]) == mp2.end()){
                mp1[str1[i]] = str2[i];
                mp2[str2[i]] = str1[i];
            }    
            else if(mp1[str1[i]] == str2[i] && mp2[str2[i]] == str1[i])
                    continue;
            else {
                c++;
                break;
            }
        }
        
        return c == 0 ? true : false;
    } 
    
};
