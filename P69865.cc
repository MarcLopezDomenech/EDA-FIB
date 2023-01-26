#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> knight_moves = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2}};

vector<pair<int,int>> bishop_moves = {{-1,-1},{-1,1},{1,1},{1,-1}};

bool casella_valida(const vector<vector<char>>& tauler, int i, int j) {
    return i >= 0 and j >= 0 and i < tauler.size() and j < tauler[0].size() 
    and tauler[i][j] != 'T';
}

int bfs_i(vector<vector<char>>& tauler, vector<vector<bool>>& visitat,const pair<int,int>& next, queue<pair<int,int>>& Q, char piece) {
    int monedes = 0;
    if (casella_valida(tauler,next.first,next.second) and not visitat[next.first][next.second]) {
        Q.push(next);
        visitat[next.first][next.second] = true;
        if (tauler[next.first][next.second] > '0' and tauler[next.first][next.second] <= '9') {
            monedes = int(tauler[next.first][next.second] - '0');
            tauler[next.first][next.second] = '.';
        }
        else if (tauler[next.first][next.second] == piece) {
            tauler[next.first][next.second] = '.';
        }
    }
    return monedes;
}

int bfs(vector<vector<char>>& tauler, int i, int j, char piece) {
    int monedes = 0;
    vector<vector<bool>> visitat (tauler.size(), vector<bool> (tauler[0].size(), false));
    queue<pair<int,int>> Q;
    Q.push({i,j});
    while (not Q.empty()) {
        pair<int,int> act = Q.front();
        Q.pop();
        if (piece == 'B') {
            for (pair<int,int> d : bishop_moves) {
                monedes += bfs_i(tauler,visitat,{act.first + d.first,act.second +
                    d.second},Q,piece);
            }
        }
        else {
            for (pair<int,int> d : knight_moves) {
                monedes += bfs_i(tauler,visitat,{act.first + d.first,act.second +
                    d.second},Q,piece);
            }
        }
    }
    return monedes;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> tauler (n, vector<char> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> tauler[i][j];
            }
        }
        int monedes = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char piece = tauler[i][j];
                if (piece == 'K' or piece == 'B') {
                    monedes += bfs(tauler, i, j, piece);
                }
            }
        }
        cout << monedes << endl;
    }
}
