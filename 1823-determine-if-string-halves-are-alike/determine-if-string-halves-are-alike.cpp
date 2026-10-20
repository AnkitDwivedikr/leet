class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int m = s.size()/2;

        int count=0, count1=0;
        for(int i=0; i<m; i++){
            char c = tolower(s[i]);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                count++;
            }
        }
        for(int i=m; i<n; i++){
             char c = tolower(s[i]);
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                count1++;
            }
        }
        if(count==count1)
        return true;
        else
        return false;
       
        
    }
};