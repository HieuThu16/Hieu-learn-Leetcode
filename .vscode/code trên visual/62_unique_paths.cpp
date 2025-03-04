#include <iostream>
#include <vector>
using namespace std;

int uniquePathsDP(int m, int n) {
    // Khởi tạo bảng dp với kích thước m x n
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    // Điền hàng đầu tiên và cột đầu tiên: chỉ có 1 cách di chuyển
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }
    
    // Tính dp[i][j] = dp[i-1][j] + dp[i][j-1]
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}

int main() {
    int m, n;
    cout << "Nhap m va n: ";
    cin >> m >> n;
    cout << "So duong di khac nhau (Cach 2 - DP): " << uniquePathsDP(m, n) << endl;
    return 0;
}
