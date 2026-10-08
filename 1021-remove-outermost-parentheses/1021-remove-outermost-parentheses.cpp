class Solution {
public:
    string removeOuterParentheses(string s) {
        string str ="";
        int count =0;
        for(int i=0;i<s.size();i++){
           if(s[i]=='('){
                    if(count>0){
                        str.push_back(s[i]);
                    }
                    count++;
           }else{
            count--;
            if(count>0){
                str.push_back(s[i]);
            }
           }

        }
        return str;
    }
};