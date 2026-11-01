class Solution {
public:
    int minOperations(int n) {
       vector<int>arr;

       for(int i=0; i<n; i++){
        arr.push_back(2*i+1);
       }

       int target = n;
       int ans = 0;
       for(int i=0; i<n/2; i++){
          ans += target-arr[i];
       }
       return ans;
    }
};