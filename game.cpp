#include <iostream>
using namespace std;

int main() {
    cout << "Game of Life!\n";
}

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = m ? board[0].size() : 0;
    
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    // 0: dead; 1: live
    // 00(0): dead -> dead (Stay)
    // 01(1): dead -> live (Birth)
    // 10(2): live -> dead (Death: under-populate + over-populate)
    // 11(3): live -> live (Stay)
    
    for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 3)) {
                        count++;
                    }
                }
                if ((board[x][y] == 1 || board[x][y] == 3) && (count < 2 || count > 3)) board[i][j] = 2;
                else if ((board[x][y] == 0 || board[x][y] == 2) && count == 3) board[i][j] = 1;
           }
     }
        
     for (int i = 0; i < m; i++) {
           for (int j = 0; j < n; j++) {
                board[i][j] %= 2;
           }
     }
}
