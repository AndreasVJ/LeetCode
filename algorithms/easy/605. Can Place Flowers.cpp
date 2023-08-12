class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.push_back(0);
        for (int i = 0; i < flowerbed.size()-1; i++) {
            if (flowerbed[i]) i++;
            else if (flowerbed[i+1] == 0) {
                i++;
                n--;
            }
        }
        return (n <= 0);
    }
};