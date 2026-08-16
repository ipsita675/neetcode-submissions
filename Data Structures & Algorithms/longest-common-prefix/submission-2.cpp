class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[strs.size()-1];

        int ct=0;
        while(ct<first.size() && first[ct]==last[ct])ct++;
        
        return first.substr(0,ct);
    }
};