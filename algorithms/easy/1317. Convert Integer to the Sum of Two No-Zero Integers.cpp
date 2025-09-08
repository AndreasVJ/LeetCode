class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n - 1;

        while (true) {
            int v1 = a;
            int v2 = b;

            bool done = true;
            while (v1) {
                if (v1%10 == 0) {
                    a++;
                    b--;
                    done = false;
                    break;
                }
                v1 /= 10;
            }
            if (!done) {
                continue;
            }

            while (v2) {
                if (v2%10 == 0) {
                    a++;
                    b--;
                    done = false;
                    break;
                }
                v2 /= 10;
            }
            if (!done) {
                continue;
            }

            break;
        }

        return {a, b};
    }
};
