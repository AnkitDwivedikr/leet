class Solution {
public:
    string reverseWords(string s) {
        int i = 0, count = 0;

        while (i < s.size() && s[i] != ' ') {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
            i++;
        }

        i++;

        while (i < s.size()) {
            int start = i, vowels = 0;

            while (i < s.size() && s[i] != ' ') {
                char c = s[i];
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    vowels++;
                }
                i++;
            }

            if (vowels == count) {
                reverse(s.begin() + start, s.begin() + i);
            }

            i++;
        }

        return s;
    }
};