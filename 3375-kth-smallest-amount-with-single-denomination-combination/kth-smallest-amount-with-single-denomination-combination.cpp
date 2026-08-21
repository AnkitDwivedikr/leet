class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {
        long long ans = 0;
        int n = coins.size();

        function<void(int, long long, int)> dfs =
        [&](int index, long long curr, int sign) {

            for (int i = index; i < n; i++) {

                long long newLcm = lcm(curr, coins[i]);

                if (newLcm > x)
                    continue;

                ans += sign * (x / newLcm);

                dfs(i + 1, newLcm, -sign);
            }
        };

        dfs(0, 1, 1);

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        sort(coins.begin(), coins.end());

        long long low = 1;
        long long high = 1LL * coins[0] * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};//akd