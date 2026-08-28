class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0, mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = i;
            }
            cnt[i] /= 2;
        }

        if (odd > 1)
            return "";

        int m = n / 2;

        auto makePal = [&](string left, int middle) {
            string right = left;
            reverse(right.begin(), right.end());

            if (middle == -1)
                return left + right;

            return left + char('a' + middle) + right;
        };

        // First try to make the smallest palindrome
        // whose left half is exactly target's left half.
        vector<int> rem = cnt;
        string left = "";

        bool possible = true;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0) {
                possible = false;
                break;
            }

            rem[x]--;
            left += target[i];
        }

        if (possible) {
            if (n % 2 == 1) {
                int t = target[m] - 'a';

                if (mid != -1 && mid > t) {
                    string ans = left + char('a' + mid);

                    string r = left;
                    reverse(r.begin(), r.end());

                    return ans + r;
                }
            }

            string ans = makePal(left, mid);

            if (ans > target)
                return ans;
        }

        // Change one position in the left half.
        for (int pos = m - 1; pos >= 0; pos--) {

            vector<int> r = cnt;
            string prefix = "";
            bool ok = true;

            for (int i = 0; i < pos; i++) {
                int x = target[i] - 'a';

                if (r[x] == 0) {
                    ok = false;
                    break;
                }

                r[x]--;
                prefix += target[i];
            }

            if (!ok)
                continue;

            int cur = target[pos] - 'a';

            for (int c = cur + 1; c < 26; c++) {

                if (r[c] == 0)
                    continue;

                string newLeft = prefix;
                newLeft += char('a' + c);

                r[c]--;

                for (int x = 0; x < 26; x++)
                    newLeft += string(r[x], char('a' + x));

                string ans = makePal(newLeft, mid);

                if (ans > target)
                    return ans;

                r[c]++;
            }
        }

        return "";
    }
};