class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        vector<vector<int>>freq(nums.size()+1);
        for(int i : nums){
            count[i]=count[i]+1;
        }
        for(const auto& m: count){
            freq[m.second].push_back(m.first);
        }
        vector<int>res;
        for(int i=freq.size()-1;i>0;--i){
            for(int a: freq[i]){
                res.push_back(a);
                if(res.size()==k){
                    return res;
                }
            }
        }
        return res;
    }
};