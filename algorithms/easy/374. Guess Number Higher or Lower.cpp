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
        unsigned int k = 1;
        for (int b = n/2; b > 0; b /= 2) {
            while (k + b <= n && guess(k + b) >= 0) k += b;
        }
        return k;
    }
};