
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans = "";

        while (sum > 0) {
            int digit = min(9, sum);
            ans += to_string(digit);
            sum -= digit;
            num--;
        }

        while (num > 0) {
            ans += '0';
            num--;
        }

        return ans;
    }
};
