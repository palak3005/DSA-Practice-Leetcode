
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevMax = -1;

            for (int start = 0; start < n && valid; start += k) {
                int mn = INT_MAX;
                int mx = INT_MIN;
                int descents = 0;

                for (int j = 0; j < k; j++) {
                    int cur = nums[start + j];
                    int next = nums[start + (j + 1) % k];

                    mn = min(mn, cur);
                    mx = max(mx, cur);

                    if (cur > next) {
                        descents++;
                    }
                }

                // A block must be a cyclic rotation of sorted order.
                if (descents > 1) {
                    valid = false;
                    break;
                }

                // The sorted blocks must also join in sorted order.
                if (start > 0 && prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};
