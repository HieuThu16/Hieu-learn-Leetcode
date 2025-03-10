#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> st ;
    for(int i = 0 ; i < n ; i++ ){
        while(!st.empty() && temperatures[i]> temperatures[st.top()]){
            int index = st.top();
            st.pop();
            answer[index] = i - index;
        }
        st.push(i);
    }
    return answer ; 
 }

// Hàm main để kiểm tra
int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    
    vector<int> result = dailyTemperatures(temperatures);

    cout << "Output: ";
    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}
