class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size(); // n -> is the size of the array

        // First we gonna sort the array given in order to apply two pointer concepts.
        sort(nums.begin(), nums.end());

        // Iterator i will to go upto n-3 index coz it shldn't same as j, k, l pointer.
        for(int i=0; i<n-3; ++i){

            // As they mention it shldn't contains any duplicate the below code does it  
            if(i>0 && nums[i] == nums[i-1]){continue;}

            // Pointer j start next after to i and to noted its shldn't exceed n-2 coz iterator j shld leave a space for k, l pointer. 
            for(int j=i+1; j<n-2; ++j){

                // shldn't contains any duplicate, so we skip the same element.
                if(j>i+1 && nums[j] == nums[j-1]){continue;}

                // Assign the pointer j, l to perform the actual two sum in sorted array.
                int k= j+1;
                int l= n-1;

                while(k<l){

                    //as they mention in the constraints they element in array can reach beyond int limit so we here used the long long 
                    // calculating the sum with the help of these pointer
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    //if sum is greater than to target then it will reduce the last pointer, if not then increase the k pointer
                    if(sum == target){  // if sum is equal to our targt then push to our ans
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        l--,k++;
                        while(k<l && nums[k] == nums[k-1]){k++;} // TO be noted inorder to have the unique elements only we need to skip the same occuring elements next to eachother
                        while(k<l && nums[l] == nums[l+1]){l--;}
                    }
                    else if(sum > target){
                        l--;
                    }else{
                        k++;
                    }
                }
            }
        }return ans;  // Happily return our ans tho ;)
    }
};