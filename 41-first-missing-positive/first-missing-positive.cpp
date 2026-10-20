class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>mp;
       // vector<int>ans;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(int j=1; j<=nums.size(); j++){
            if(mp[j]==0){
               // ans.push_back(nums[j]);
               return j;
            }
        }
        return nums.size()+1;
    }
};