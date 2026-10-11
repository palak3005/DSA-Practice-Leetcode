class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left =0;
        int right =0;
        int count=0;
        while(right<nums.size()){
           if(nums[right]!=val){
                   count++;
                nums[left]=nums[right]; 
                left++;
                }
            
            right++;
        }
return count;
    }
};