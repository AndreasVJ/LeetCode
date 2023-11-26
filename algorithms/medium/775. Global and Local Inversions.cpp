class Solution {
public:
    int globalInversions = 0;
    queue<int> leftQueue;
    queue<int> rightQueue;

    bool isIdealPermutation(vector<int>& nums) {
        int localInversions = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i+1]) localInversions++;
        }
        mergeSort(nums, 0, nums.size());
        return localInversions == globalInversions;
    }

    void merge(vector<int>& arr, int l, int m, int r) {
        for (int i = l; i < m; i++) {
            leftQueue.push(arr[i]);
        }
        for (int i = m; i < r; i++) {
            rightQueue.push(arr[i]);
        }

        int a = l;

        while (!leftQueue.empty() && ! rightQueue.empty()) {
            if (leftQueue.front() < rightQueue.front()) {
                arr[a] = leftQueue.front();
                leftQueue.pop();
            }
            else {
                arr[a] = rightQueue.front();
                rightQueue.pop();
                globalInversions += leftQueue.size();
            }
            a++;
        }

        while (!leftQueue.empty()) {
            arr[a] = leftQueue.front();
            leftQueue.pop();
            a++;
        }
        while (!rightQueue.empty()) {
            arr[a] = rightQueue.front();
            rightQueue.pop();
            a++;
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (r - l == 1) return;

        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m, r);
        merge(arr, l, m, r);
    }
};