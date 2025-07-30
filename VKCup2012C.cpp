#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To consume the newline after the number

    vector<string> commands(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, commands[i]);
    }

    stack<string> st1, st2;

    for (int i = 0; i < n; ++i) {
        string cmd = commands[i];

        if (cmd == "pwd") {
            // Print path
            string res = "/";
            vector<string> temp;

            // Transfer stack to temp vector (since we can't directly iterate stack)
            while (!st1.empty()) {
                temp.push_back(st1.top());
                st1.pop();
            }

            // Rebuild and print
            for (int j = temp.size() - 1; j >= 0; --j) {
                res += temp[j] + "/";
                st1.push(temp[j]); // push back to original
            }

            cout << res << "\n";

        } else if (cmd.substr(0, 3) == "cd ") {
            string path = cmd.substr(3);
            if (path[0] == '/') {
                // Absolute path: reset
                while (!st1.empty()) st1.pop();
                path = path.substr(1);
            }

            string part = "";
            for (int j = 0; j <= path.size(); ++j) {
                if (j == path.size() || path[j] == '/') {
                    if (part == "..") {
                        if (!st1.empty()) st1.pop(); // Go up
                    } else if (!part.empty()) {
                        st1.push(part); // Go into folder
                    }
                    part.clear();
                } else {
                    part += path[j];
                }
            }
        }
    }

    return 0;
}