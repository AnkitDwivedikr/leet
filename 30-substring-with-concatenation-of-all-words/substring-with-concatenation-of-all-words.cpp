class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int n = s.size();
        int m = words.size();

        if (m == 0) return ans;

        int len = words[0].size();
        int totalLen = m * len;

        if (n < totalLen) return ans;

        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        for (int start = 0; start < len; start++) {

            unordered_map<string, int> window;

            int left = start;
            int count = 0;

            for (int right = start; right + len <= n; right += len) {

                string word = s.substr(right, len);

                if (mp.find(word) != mp.end()) {

                    window[word]++;
                    count++;

                    while (window[word] > mp[word]) {

                        string leftWord = s.substr(left, len);

                        window[leftWord]--;
                        left += len;
                        count--;
                    }

                    if (count == m) {

                        ans.push_back(left);

                        string leftWord = s.substr(left, len);
                        window[leftWord]--;
                        left += len;
                        count--;
                    }
                }
                else {

                    window.clear();
                    count = 0;
                    left = right + len;
                }
            }
        }

        return ans;
    }
};