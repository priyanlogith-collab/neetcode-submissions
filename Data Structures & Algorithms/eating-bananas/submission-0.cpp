class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high = *max_element(piles.begin(), piles.end());
        int ans;
        while(low <= high){
            int mid = low + (high-low)/2;
            long long  th=0;
            for(auto x : piles){
                th += (x + mid -1)/mid;
            }
            if(th <= h){
                // ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};