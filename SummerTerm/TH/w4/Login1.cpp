#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    unordered_map<string, string> database;

    for (int i = 0; i < n; ++i) {
        string username, password;
        cin >> username >> password;
        database[username] = password;
    }

    for (int i = 0; i < q; ++i) {
        string query;
        cin >> query;
        if (database.find(query) != database.end()) cout << database[query] << '\n';
        else cout << "Chua Dang Ky!" << '\n';
    }

    return 0;
}