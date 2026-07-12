class Solution {
public:
    void merge(vector<int> &nums , int l, int mid, int h){
        int i=l;
        int j= mid +1;
        vector<int> temp;
        while(i <= mid && j <= h){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }else temp.push_back(nums[j++]);
        }
        while(i <= mid){
            temp.push_back(nums[i++]);
        }
        while(j <= h){
            temp.push_back(nums[j++]);
        }
        for(int k=l; k<=h; ++k){
            nums[k] = temp[k-l];
        }
    }

    void mergesort(vector<int> &nums, int l, int h){
        if(l < h){
            int mid = (l+h)/2;
            mergesort(nums,l,mid);
            mergesort(nums,mid+1,h);
            merge(nums,l,mid,h);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};