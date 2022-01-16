#include <bits/stdc++.h>
#include <limits.h>
#define endl '\n'
#define pb push_back
using namespace std;

int M, S = 0;

void CommandLineProcessor(vector<string>& tokens) {
    if (tokens.size() == 1) {
        if (tokens[0] == "all") {
            // S = pow(2, 21) - 1;
            S = (1 << 21) - 1;
        }
        else if (tokens[0] == "empty") {
            S = 0;
        }
    }
    else if (tokens.size() == 2) {
        int n = stoi(tokens[1]);
        if (tokens[0] == "add") {
            S = S | (1 << n);
        }
        else if (tokens[0] == "remove") {
            S = S & ~(1 << n);
        }
        else if (tokens[0] == "check") {
            if (S & (1 << n)) {
                cout << 1 << endl;
            } 
            else {
                cout << 0 << endl;
            } 
        }
        else if (tokens[0] == "toggle") {
            S = S ^ (1 << n);
        }
    }
}

void Input() {
    string command, token;
    istringstream ss;
    vector<string> tokens;
    cin >> M;
    cin.ignore();
    for (int i = 0; i < M; i++) {
        getline(cin, command);
        ss.str(command);
        while (ss >> token) tokens.pb(token);
        CommandLineProcessor(tokens);
        while (!tokens.empty()) tokens.pop_back();
        ss.clear();
    }
}

void Solve() {
    Input();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Solve();
    return 0;
}