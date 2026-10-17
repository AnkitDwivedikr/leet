class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push({});

        int n = formula.size();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                st.push({});
                i++;
            } 
            else if (formula[i] == ')') {
                map<string, int> temp = st.top();
                st.pop();
                i++;

                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }

                if (num == 0) num = 1;

                for (auto x : temp) {
                    st.top()[x.first] += x.second * num;
                }
            } 
            else {
                string atom = "";
                atom += formula[i++];

                while (i < n && islower(formula[i])) {
                    atom += formula[i++];
                }

                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }

                if (num == 0) num = 1;
                st.top()[atom] += num;
            }
        }

        string ans = "";

        for (auto x : st.top()) {
            ans += x.first;
            if (x.second > 1) ans += to_string(x.second);
        }

        return ans;
    }
};