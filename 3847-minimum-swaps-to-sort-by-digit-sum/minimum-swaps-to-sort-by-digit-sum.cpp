class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a;

        for (int x : nums) {
            a.push_back({digitSum(x), x});
        }

        sort(a.begin(), a.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[a[i].second] = i;
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || pos[nums[i]] == i)
                continue;

            int j = i, count = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = pos[nums[j]];
                count++;
            }

            ans += count - 1;
        }

        return ans;
    }
};