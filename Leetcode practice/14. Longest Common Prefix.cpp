class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if((int)strs.size()==0) return "";
        int ret = 0;
        int mnl = 1000000000;
        for(int i = 0;i<strs.size();i++) mnl = min(mnl,(int)strs[i].size());
        string prefix = "";
        for(int l = 0;l<mnl;l++){
            char ch = strs[0][l];
            for(int i = 1;i<strs.size();i++) if(strs[i][l]!=ch) return prefix; 
            prefix.push_back(ch);
        }
        return prefix;
        
    }
};