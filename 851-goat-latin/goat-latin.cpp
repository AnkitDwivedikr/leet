class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans = "";
        int i=0, count=1;
        while(i<sentence.size()){
            string word = "";
            while(i<sentence.size() && sentence[i]!=' '){
                word += sentence[i];
                i++;
            }

                char c = tolower(word[0]);
                if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                    ans += word;
                }
                else{
                    ans += word.substr(1) + word[0];
                }
                ans += "ma";

                for(int j=0; j<count; j++){
                    ans += 'a';
                }
                count++;
                
                if(i<sentence.size()){
                    ans += ' ';
                    i++;
                }
        }
        return ans;

    }
};