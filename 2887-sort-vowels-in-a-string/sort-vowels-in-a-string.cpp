class Solution {
public:
    string sortVowels(string s) {
        //vector<string>ans;
        string ans = "";
        for(int i=0; i<s.size(); i++){
            char c = tolower(s[i]);
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                ans += s[i];
            }
        }
        sort(ans.begin(),ans.end());
        int j=0;
        for(int i=0; i<s.size(); i++){
            char c = tolower(s[i]);
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                s[i]=ans[j];
                j++;
            }
        }
        return s;
    }
};