#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    // Stack to keep track of open brackets
    stack<char> st;

    // Loop through each character in the string
    for (char c : s) {
        // Push open brackets onto the stack
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // Check for closing brackets
        else {
            // If stack is empty or top of stack doesn't match, it's invalid
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top != '(') || 
                (c == '}' && top != '{') || 
                (c == ']' && top != '[')) {
                return false;
            }
            // Pop the matching open bracket
            st.pop();
        }
    }

    // If stack is empty, the string is valid
    return st.empty();
}

int main() {
    string s = "{[()]}";  // Example input
    if (isValid(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is invalid." << endl;
    }
    return 0;
}
