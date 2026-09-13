class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        // This one is for detecting the cycle

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }

        // We dont know whether the pointer are points to duplicate value or not

        slow = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;    
    }
};