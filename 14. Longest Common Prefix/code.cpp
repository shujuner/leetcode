class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        int minLen=strs[0].size();
        int id=0;
        int i;
        for(i=1;i<strs.size();++i)
        {
            if(strs[i].size()<minLen)
            {
                minLen=strs[i].size();
                id=i;
            }
        }
        if(id!=0)
        {
            string temp(strs[id]);
            strs[id]=strs[0];
            strs[0]=temp;
        }
        string prefix("");
        for(int idx=0; strs.size()>0; prefix+=strs[0][idx], ++idx)
            for(i=0; i<strs.size(); ++i)
                if(idx >= strs[i].size() ||(i > 0 && strs[i][idx] != strs[0][idx]))
                    return prefix;
        return prefix;
    }
};