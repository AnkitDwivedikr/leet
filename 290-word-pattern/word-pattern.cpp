class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;

        while (ss >> word)
            words.push_back(word);

        if (words.size() != pattern.size())
            return false;

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (!mp1.count(c) && !mp2.count(w)) {
                mp1[c] = w;
                mp2[w] = c;
            } else {
                if (mp1[c] != w || mp2[w] != c)
                    return false;
            }
        }

        return true;
    }
};//akd