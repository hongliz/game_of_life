#include <iostream>
#include <vector>
#define XX 25
#define YY 25
using namespace std;

void gameOfLife(vector<vector<int>>& board);

int main() {
    cout << "Game of Life!\n";
    vector<vector<int>> board(XX, vector<int>(YY,0));
    
    board[10][11]=1; board[11][12]=1; board[12][10]=1; board[12][11]=1; board[12][12]=1;
    
    char ch;
    while ((ch = getchar()) != 'q')
    {
        gameOfLife(board);
    }
}

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = m ? board[0].size() : 0;
    
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    // 0: dead; 1: live
    // bit1 is current generation; bit0 is next generation
    // 00(0): dead -> dead (Stay)
    // 01(1): dead -> live (Birth)
    // 10(2): live -> dead (Death: under-populate + over-populate)
    // 11(3): live -> live (Stay)
    
    for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
                int count = 0;
              
                // determine # of live neighbours
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 2 || board[x][y] == 3)) {
                        count++;
                    }
                }
              
                // Death
                if ((board[i][j] == 2 || board[i][j] == 3) && (count < 2 || count > 3)) board[i][j] = 2;
                // Birth
                else if ((board[i][j] == 0 || board[i][j] == 1) && count == 3) board[i][j] = 1;
                // Stay -- right shift 1 bit
                else board[i][j] /= 2;
           }
     }
       
     // output result and then move next generation(bit0) to current generation(bit1), preparing for the next iteration 
     for (int i = 0; i < m; i++) {
           for (int j = 0; j < n; j++) {
                int temp = board[i][j] % 2;
                cout << temp;
                board[i][j] = temp *2;
           }
           cout << endl;
     }
}
