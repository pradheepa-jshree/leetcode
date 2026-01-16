class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from last digit to first
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;   // Just add 1
                return digits;
            }
            digits[i] = 0;     // If it's 9, make it 0 and carry continues
        }

        // If all digits were 9, we need an extra digit at front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
