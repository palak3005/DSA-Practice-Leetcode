
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> v(n);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            v[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, v[i]);
        }

        long long left = 0, right = maxi;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long operations = 0;

            for (int diff : v) {
                if (diff > mid) {
                    operations += diff - mid;
                }
            }

            if (operations <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        long long ans = 0;
        long long operations = 0;

        for (int diff : v) {
            int reduced = min(diff, (int)left);
            ans += 1LL * reduced * reduced;
            operations += diff - reduced;
        }

        for (int diff : v) {
            if (operations == k) break;
            if (diff > left) continue;

            // Remaining reductions are handled below
        }

        // Calculate the exact minimum using a frequency array.
        vector<long long> freq(maxi + 1, 0);

        for (int diff : v) {
            freq[diff]++;
        }

        long long remaining = k;

        for (int d = maxi; d > 0 && remaining > 0; d--) {
            long long take = min(freq[d], remaining);
            freq[d] -= take;
            freq[d - 1] += take;
            remaining -= take;
        }

        ans = 0;

        for (int d = 0; d <= maxi; d++) {
            ans += freq[d] * d * d;
        }

        return ans;
    }
};

