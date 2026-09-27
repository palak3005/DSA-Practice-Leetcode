class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>f;
        f['I'] = 1;
        f['V'] = 5;
        f['X'] = 10;
        f['L'] = 50;
        f['C'] = 100;
        f['D'] = 500;
        f['M'] = 1000;
         int ans =0;
      for(int i=0;i<s.size();i++){
        int left = f[s[i]];
            int right = f[s[i+1]];
            if(right>left){
            ans -=left;
            }else{
                ans+=left;
            }
      }
      return ans;
    }
};