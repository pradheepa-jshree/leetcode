class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numMap;
        for (int i = 0; i < nums.size(); ++i) {
            int second_num = target - nums[i];
            if (numMap.find(second_num) != numMap.end()) {
                return {numMap[second_num], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};