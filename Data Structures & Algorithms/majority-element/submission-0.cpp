class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x : nums){
            mp[x]++;
        }
        int n = nums.size()/2;
        for(auto x : mp){
            if(x.second > n){
                return x.first ;
            }
        }
        return 0;
    }
};