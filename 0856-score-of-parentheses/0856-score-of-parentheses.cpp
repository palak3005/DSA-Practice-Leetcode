class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int>vector;
        int score =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                vector.push_back(score);
                score =0;
            }else{
                if(s[i-1]=='('){
                    score = vector.back()+1;
                }else{
                    score = vector.back()+(2*score);
                }
                vector.pop_back();
            }
        }
        return score;
    }
};