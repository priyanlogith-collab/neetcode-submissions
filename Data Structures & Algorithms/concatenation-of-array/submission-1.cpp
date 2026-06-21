class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        int n=2*nums.size();
        while(n--){
            ans.push_back(nums[i%nums.size()]);
            i++;
        } return ans;
    }
};