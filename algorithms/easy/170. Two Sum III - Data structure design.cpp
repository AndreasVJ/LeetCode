class TwoSum {
public:
    unordered_map<int, int> nums;

    void add(int number) {
        nums[number]++;
    }

    bool find(int value) {
        if (value < -20e5 || 20e5 < value) return false;
        for (auto &[key, count] : nums) {
            if (nums.find(value - key) != nums.end()) {
                if (value - key == key) {
                    if (count > 1) return true;
                }
                else return true;
            }
        }
        return false;
    }
};