class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long inc = 0, dec = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long diff = nums2[i] - nums1[i];

            if (k == 0) {
                if (diff != 0) return -1;
                continue;
            }

            if (diff % k != 0) return -1;

            if (diff > 0)
                inc += diff / k;
            else
                dec += -diff / k;
        }

        if (inc != dec) return -1;

        return inc;
    }
};//akd