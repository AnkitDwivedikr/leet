class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string &digits, int index, string curr) {
        if (index == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for (char ch : letters) {
            solve(digits, index + 1, curr + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        solve(digits, 0, "");
        return ans;
    }
};