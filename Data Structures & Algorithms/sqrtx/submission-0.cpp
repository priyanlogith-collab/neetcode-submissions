class Solution {
public:
    int mySqrt(int x) {
        int low=0, high=x;
        while(low <= high){
            int mid = low + (high-low)/2;
            long long root = (long long)mid*mid;
            if(root == x){
                return mid;
            }else if(root > x){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return high;
    }
};