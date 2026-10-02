class Solution {
public:
    int compress(vector<char>& chars) {
        string s ="";
        int left =0;
        int right =0;
        int len =0;
        int pointer =0;
        while(right<chars.size()){
            s = chars[left];
            while(right<chars.size() && chars[right]==chars[left]){
                right++;
            }
            len = right - left;
            if(len>1){
            s = s + to_string(len);
            }
           
            for(int i=0;i<s.length();i++){
                chars[pointer] = s[i];
                pointer++;
            }
            left=right;
        }
        return pointer;
    }
};