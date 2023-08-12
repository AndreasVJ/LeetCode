class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int k =  letters.size() - 1;
        
        for (int b = letters.size()/2; b > 0; b /= 2) {
            while (k - b >= 0 && letters[k - b] > target) k -= b;
        }
        
        return letters[k] > target ? letters[k] : letters[0];
    }
};