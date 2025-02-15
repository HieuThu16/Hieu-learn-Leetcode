class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right =
                    mid; // Move left since mid might be the first bad version
            } else {
                left = mid + 1; // Move right since mid is good
            }
        }
        return left; // `l
    }
};