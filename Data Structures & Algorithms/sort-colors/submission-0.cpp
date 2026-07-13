class Solution {
public:
    void countsort(vector<int> &nums){
        int max = *max_element(nums.begin(), nums.end());

        vector<int> count(max+1);

        // freq counting

        for(auto x : nums){
            count[x]++;
        }

        //prefix sum of count 

        for(int i=1; i<count.size(); i++){
            count[i] += count[i-1];
        }

        // sorting in ans  

        vector<int> ans(nums.size());
        for(int i= nums.size()-1; i>=0; i--){
            ans[count[nums[i]]-1] = nums[i];
            count[nums[i]]--;
        }

        // storing back into nums

        for(int i=0; i< nums.size(); i++){
            nums[i] = ans[i];
        }

    }
    void sortColors(vector<int>& nums) {
        countsort(nums);
    }
};