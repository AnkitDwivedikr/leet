class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

    int n = digits.size();
    int curr = n-1;
    
    while (curr >= 0) {

    if (digits[curr] < 9) {
        digits[curr]++;
        return digits;
    }

    digits[curr] = 0;
    curr--;
}

digits.insert(digits.begin(), 1);
return digits; 
    }
};