class Solution {
public:
vector<string>v;
bool isValid(string &str) {
     int count = 0; 
     for(char ch : str) {
         if(ch == '(') {
             count++;
              } else if(ch == ')') { 
                count--;
              
     
     if(count < 0) return false; 
         }
     }      
     return count == 0;
    }
 void fun(string &s,string& str,int i){
    if(i==s.size()){
        if(isValid(str)){
             v.push_back(str);
        }
     return;
    } 
         if(s[i]!='('&& s[i]!=')'){
            str.push_back(s[i]);
                fun(s,str,i+1);
                str.pop_back();
            }else{
                 str.push_back(s[i]);
                fun(s,str,i+1);
               
             str.pop_back();
             fun(s,str,i+1);
            }
        return;
        };
    vector<string> removeInvalidParentheses(string s) {
        string str ="";
        fun(s,str,0);
        int maxi=0;
        for(int i=0;i<v.size();i++){
            maxi = max( maxi,int(v[i].length()));
        }
        set<string>v2;
        for(int i=0;i<v.size();i++){
            if(v[i].length()==maxi){
            v2.insert(v[i]);
            }
        }
        v.clear();
        for(auto ch : v2){
           v.push_back(ch);
        }
        return v;
    }
};