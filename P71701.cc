#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<char>>& T) {
    for (int i = 0; i < T.size(); ++i) {
        for (int j = 0; j < T[0].size(); ++j) cout << T[i][j];
        cout << endl;
    }
    cout << string(10,'-') << endl;
}

inline bool pos_ok(int i, int j, int n) {
    return i >= 0 and i < n and j >= 0 and j < n;
}

void solve(vector<vector<char>>& T, int i, int j, int kings) {
    if (kings == 0) print(T);
    else if (i == T.size()) return;
    else if (j == T[i].size()) solve(T,i + 1,0,kings);

    else {
        bool no_threat = true;
        for (int di = -1; di <= 0; ++di) for (int dj = -1; dj <= 1; ++dj) if ((di == -1 or dj == -1) and pos_ok(i + di, j + dj, T.size()) and T[i + di][j + dj] == 'K') no_threat = false;

        if (no_threat) {T[i][j] = 'K'; solve(T,i,j + 1,kings - 1);}
        T[i][j] = '.'; solve(T,i,j + 1,kings);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<char>> T(n,vector<char>(n,'.'));
    solve(T,0,0,k);
}