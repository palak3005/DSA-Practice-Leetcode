class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>f;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]=i;
        }
        vector<int>value;
        for(int i=0;i<nums.size();i++){
            int ans = target-nums[i];
            if(f.find(ans)!=f.end() && f[ans]!=i){
               return {i,f[ans]};
            }
        }
        return value;
    }
};