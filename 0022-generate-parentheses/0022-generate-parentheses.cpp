class Solution {
      
public:
bool isValid(string& str){
int count =0;
for(char ch :str){
    if(ch=='(') count++;
    else count--;
     if(count < 0)
            return false;
}
return (count==0) ;

}
 vector<string>ans;
   void solve(string& s , int n){
     if(s.length()==2*n){
        if(isValid(s)){
         ans.push_back(s);
        }
        return;
     } 
    

     s.push_back('(');
      solve(s,n);
        s.pop_back();
        s.push_back(')');
     solve(s,n); 
       s.pop_back();
        return;
}

    vector<string> generateParenthesis(int n) {
       string str="";
       solve(str,n); 
      
     return ans;
    }
};