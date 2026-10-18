class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<vector<long long>> C(n + 1, vector<long long>(n + 1, 1));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        function<long long(vector<int>&)> solve = [&](vector<int>& arr) -> long long {
            if (arr.size() <= 2) return 1;

            vector<int> left, right;
            int root = arr[0];

            for (int i = 1; i < arr.size(); i++) {
                if (arr[i] < root) left.push_back(arr[i]);
                else right.push_back(arr[i]);
            }

            long long ways = C[left.size() + right.size()][left.size()];
            ways = ways * solve(left) % MOD;
            ways = ways * solve(right) % MOD;

            return ways;
        };

        return (solve(nums) - 1 + MOD) % MOD;
    }
};//akd 