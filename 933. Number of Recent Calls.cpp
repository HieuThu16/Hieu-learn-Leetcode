#include <queue>

class RecentCounter {
private:
    std::queue<int> requests;

public:
    RecentCounter() {}

    int ping(int t) {
        requests.push(t);
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop(); // Loại bỏ các yêu cầu cũ hơn 3000ms
        }
        return requests.size();
    }
};
