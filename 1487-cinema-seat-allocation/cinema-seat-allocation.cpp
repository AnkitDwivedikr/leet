class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, int> mp;

        for(auto seat : reservedSeats) {
            mp[seat[0]] |= (1 << seat[1]);
        }

        int ans = (n - mp.size()) * 2;

        for(auto x : mp) {
            int mask = x.second;

            bool left = true;
            bool middle = true;
            bool right = true;

            for(int i = 2; i <= 5; i++) {
                if(mask & (1 << i))
                    left = false;
            }

            for(int i = 4; i <= 7; i++) {
                if(mask & (1 << i))
                    middle = false;
            }

            for(int i = 6; i <= 9; i++) {
                if(mask & (1 << i))
                    right = false;
            }

            if(left && right)
                ans += 2;
            else if(left || middle || right)
                ans += 1;
        }

        return ans;
    }
};//akd