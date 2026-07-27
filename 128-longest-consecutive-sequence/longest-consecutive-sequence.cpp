class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>res(nums.begin(),nums.end());
        int streak=0;
        for(int num:res){
            if(res.find(num-1)==res.end()){
                int length=1;
                while(res.find(num+length)!=res.end()){
                    length++;
                }
                streak=max(streak,length);
            }
        }
        return streak;
    }
};