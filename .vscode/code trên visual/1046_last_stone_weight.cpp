#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxHeap(stones.begin(), stones.end());
    while(maxHeap.size() > 1 ){
        int y = maxHeap.top(); maxHeap.pop();
        int x = maxHeap.top(); maxHeap.pop();
        if(x!=y)  maxHeap.push(y-x);
    }
    return maxHeap.empty() ? 0 : maxHeap.top(); 
}

// Hàm kiểm tra
int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << "Trong luong cua vien da cuoi cung: " << lastStoneWeight(stones) << endl;
    return 0;
}
