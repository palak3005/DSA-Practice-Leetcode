#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::stack<int> openIdxs;
        std::string result = "";
        
        for (char c : s) {
            if (c == '(') {
                // Store the current length of the result string
                openIdxs.push(result.length());
            } else if (c == ')') {
                // Pop the starting index for the reverse operation
                int start = openIdxs.top();
                openIdxs.pop();
                // Reverse the substring from 'start' to the end of the current result
                std::reverse(result.begin() + start, result.end());
            } else {
                // Append regular lowercase characters
                result += c;
            }
        }
        
        return result;
    }
};
