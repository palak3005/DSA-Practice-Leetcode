class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int left =0;
    int right =0;
     int ans =0;
       unordered_map<char,int>f;
     while(right<s.size() ){
           f[s[right]]++;
        while( f[s[right]]>1){
            f[s[left]]--;
          left++;
        }
       
        int value = right-left+1;
        ans = max(ans,value);
        
        right++;
     }   
     return ans;
    }
};