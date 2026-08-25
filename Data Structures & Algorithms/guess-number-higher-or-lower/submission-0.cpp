/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        int value;
        while(low <= high){
            int mid = low + (high - low)/2;
            value = guess(mid);
            if(value == -1){
                high = mid-1;
            }else if(value == 1){
                low = mid+1;
            }else if(value == 0){
                return mid;
            }
        }
        return 0;
    }
};