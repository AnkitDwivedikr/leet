class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        // for(auto x : mp)){
        //     if(x.second>1){
        //         ans.push_back(x.first);
        //     }
        // }
        for(int i=0; i<=nums.size(); i++){
            if(mp[i]>1){
                return i;
            }
        }
        return -1;
    }
};