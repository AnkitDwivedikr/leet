class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string st;

        for(char ch:num){

            while(!st.empty() && k>0 && st.back()>ch){
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }
        while(k>0 && !st.empty()){
            st.pop_back();
            k--;
        }

        int i=0;
        while(st.size()>i && st[i]== '0' ){
            i++;
        }
        st = st.substr(i);

        if(st.empty()){
            return "0";
        }

        return st;

    }
};