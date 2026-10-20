class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int>m;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(int j=1; j<=nums.size(); j++){
            if(m[j]>1){
                ans.push_back(j);
            }
        }
        return ans;
    }
};