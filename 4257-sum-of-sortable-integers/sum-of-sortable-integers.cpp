class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n), suffMin(n), drops(n, 0);

        prefMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
            drops[i] = drops[i - 1] + (nums[i - 1] > nums[i]);
        }

        suffMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;

            for (int i = k; i < n; i += k) {
                if (prefMax[i - 1] > suffMin[i]) {
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;

            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;
                int internalDrops = drops[end] - drops[start];
                int cyclicDrop = (nums[end] > nums[start]);

                if (internalDrops + cyclicDrop > 1) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans += k;
        }

        return ans;
    }
};//akd