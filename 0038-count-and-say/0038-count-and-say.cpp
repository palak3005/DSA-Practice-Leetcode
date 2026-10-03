class Solution {
public:
string ans="1";
string rle(int n){
    if(n==1) return ans;
    rle(n-1);
        int count =0;
        int left =0;
        int right =0;
        string s ="";
        while(right<ans.size()){ 
        while(right<ans.size() && ans[right]==ans[left]){
             count++;
               right++;
        }
             s+=to_string(count)+ans[left];
             left = right;
             count=0;
        }
         ans = s;
         return ans;
};
  
    string countAndSay(int n) {
      return  rle(n);
    }
};