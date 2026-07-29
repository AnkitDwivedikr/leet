class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> mp;

        string word;
        int maxi = 0;
        string ans;

        for (int i = 0; i <= paragraph.size(); i++) {

            if (i < paragraph.size() && isalpha(paragraph[i])) {
                word += tolower(paragraph[i]);
            } else {
                if (!word.empty()) {
                    if (ban.find(word) == ban.end()) {
                        mp[word]++;

                        if (mp[word] > maxi) {
                            maxi = mp[word];
                            ans = word;
                        }
                    }
                    word.clear();
                }
            }
        }

        return ans;
    }
};