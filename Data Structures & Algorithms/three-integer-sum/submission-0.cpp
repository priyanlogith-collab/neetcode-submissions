class Solution {
public:  // -4 -1 -1  0  1  2   ||  -3 -2  0  2  4 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; ++i){
            int j=i+1, k=n-1;
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                    //while(j<k && nums[j] == nums[j-1]){j++;}
                }else if(sum > 0){
                    k--;
                    //while(k>j && nums[k] == nums[k+1]){k--;}
                }else if(sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]){j++;}
                    while(k>j && nums[k] == nums[k+1]){k--;}
                }
            }
        }
        return ans;
    }
};