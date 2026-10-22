class Solution {
public:
    int countArrangement(int n) {
        vector<bool> used(n + 1, false);
        return solve(1, n, used);
    }

    int solve(int pos, int n, vector<bool>& used) {
        if (pos > n) return 1;

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (!used[i] && (i % pos == 0 || pos % i == 0)) {
                used[i] = true;
                ans += solve(pos + 1, n, used);
                used[i] = false;
            }
        }

        return ans;
    }
};//akd