class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
        {
            vector<vector<int>> v;
            return v;
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<nums.size()-2;++i)
        {
            int target=nums[i];
            int pre=i+1,end=nums.size()-1;
            while(pre<end)
            {
                if((nums[pre]+nums[end])==-target)
                {
                    int temp1=nums[pre],temp2=nums[end];
                    result.push_back({target,nums[pre],nums[end]});
                    while (pre < end && nums[end] == temp1) pre++;
                    while (pre < end && nums[end] == temp2) end--;
                }
                else if((nums[pre]+nums[end])>-target)
                {
                    end--;
                }
                else
                {
                    pre++;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
        }  
        return result;
    }
};