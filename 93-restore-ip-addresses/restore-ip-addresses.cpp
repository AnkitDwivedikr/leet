class Solution {
public:
    vector<string> ans;

    void solve(string& s, int index, int parts, string curr) {
        if (parts == 4) {
            if (index == s.size()) {
                curr.pop_back();
                ans.push_back(curr);
            }
            return;
        }

        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string part = s.substr(index, len);

            if (part.size() > 1 && part[0] == '0')
                continue;

            int num = stoi(part);

            if (num > 255)
                continue;

            solve(s, index + len, parts + 1, curr + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return ans;
    }
};//akd