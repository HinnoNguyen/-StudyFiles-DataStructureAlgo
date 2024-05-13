#include <bits/stdc++.h>
using namespace std;

bool KTLatex(const string& s) {
    stack<char> st;
    map<char, char> matching_brackets = {{')', '('}, {'}', '{'}, {']', '['}};

    for (char c : s) {
        switch (c) {
            case '(':
            case '{':
            case '[':
                st.push(c);
                break;
            case ')':
            case '}':
            case ']':
                if (st.empty() || st.top() != matching_brackets[c]) {
                    return false;
                }
                st.pop();
                break;
            default:
                break;
        }
    }

    return st.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    getline(cin, s);

    if (KTLatex(s)) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}