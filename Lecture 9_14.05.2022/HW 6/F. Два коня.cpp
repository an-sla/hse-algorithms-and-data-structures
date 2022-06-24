#include <iostream>
#include <queue>
#include <map>
#include <vector>


using namespace std;
const int N = 8;
const int INF = 1e9;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

vii horse_first(N, vi(N, INF)), horse_second(N, vi(N, INF));

map<char, int> alpha = {
    { 'a', 0 },
    { 'b', 1 },
    { 'c', 2 },
    { 'd', 3 },
    { 'e', 4 },
    { 'f', 5 },
    { 'g', 6 },
    { 'h', 7 }
};
map<char, char> nums = {
    { '1', 0 },
    { '2', 1 },
    { '3', 2 },
    { '4', 3 },
    { '5', 4 },
    { '6', 5 },
    { '7', 6 },
    { '8', 7 }
};


void fill(vii &board, queue<pii> &q, int x, int y) {
    if (x < 6 && y > 0 && board[x + 2][y - 1] == INF) {
        board[x + 2][y - 1] = board[x][y] + 1;
        q.push({x + 2, y - 1});
    }
    if (x > 0 && y < 6 && board[x - 1][y + 2] == INF) {
        board[x - 1][y + 2] = board[x][y] + 1;
        q.push({x - 1, y + 2});
    }
    if (x < 6 && y < 7 && board[x + 2][y + 1] == INF) {
        board[x + 2][y + 1] = board[x][y] + 1;
        q.push({x + 2, y + 1});
    }
    if (x < 7 && y < 6 && board[x + 1][y + 2] == INF) {
        board[x + 1][y + 2] = board[x][y] + 1;
        q.push({x + 1, y + 2});
    }
    if (x > 0 && y > 1 && board[x - 1][y - 2] == INF) {
        board[x - 1][y - 2] = board[x][y] + 1;
        q.push({x - 1, y - 2});
    }
    if (x > 1 && y > 0 && board[x - 2][y - 1] == INF) {
        board[x - 2][y - 1] = board[x][y] + 1;
        q.push({x - 2, y - 1});
    }
    if (x > 1 && y < 7 && board[x - 2][y + 1] == INF) {
        board[x - 2][y + 1] = board[x][y] + 1;
        q.push({x - 2, y + 1});
    }
    if (x < 7 && y > 1 && board[x + 1][y - 2] == INF) {
        board[x + 1][y - 2] = board[x][y] + 1;
        q.push({x + 1, y - 2});
    }
}




int main() {
    bool possible = false;

    int x1, y1, x2, y2;
    queue<pii> q;

    string read;
    getline(cin, read);

    x1 = alpha[read[0]];
    y1 = nums[read[1]];
    x2 = alpha[read[3]];
    y2 = nums[read[4]];

    horse_first[x1][y1] = 0;    
    horse_second[x2][y2] = 0;
    q.push({x1, y1});


    while (!q.empty()) {
        pii current = q.front();
        q.pop();
        int x = current.first, y = current.second;
        fill(horse_first, q, x, y);
    }
    

    q.push({ x2, y2 });


    while (!q.empty() && !possible) {
        pii current = q.front();
        q.pop();
        
        int x = current.first; 
        int y = current.second;

        if (horse_first[x][y] == horse_second[x][y]) {
            possible = true;
            cout << horse_first[x][y] << "\n";
        }
        fill(horse_second, q, x, y);
    }
    if (!possible) {
        cout << -1;
    }
    return 0;
}