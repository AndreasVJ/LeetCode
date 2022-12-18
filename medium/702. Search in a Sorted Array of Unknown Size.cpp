/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        
        int k = 0;

        for (int b = 10e4; b > 0; b /= 2) {
            while (k <= 10e4 - b && reader.get(k + b) <= target) k += b;
        }

        return reader.get(k) == target ? k : -1;
    }
};