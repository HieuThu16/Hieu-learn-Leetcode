class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0) {
                return mid; // Đoán đúng số
            } else if (res == -1) {
                right = mid - 1; // Giảm phạm vi tìm kiếm
            } else {
                left = mid + 1; // Tăng phạm vi tìm kiếm
            }
        }
        return -1; // Trường hợp không tìm thấy (không xảy ra nếu luôn có số hợp lệ)
    }
};
