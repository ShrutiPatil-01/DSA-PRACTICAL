#include <iostream> 
using namespace std; 
 
const int N = 8; 
int board[N][N];
bool isSafe(int r, int c) {  
    for (int i = 0; i < c; i++) 
        if (board[r][i]) return false;  
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) return false; 
    for (int i = r, j = c; i < N && j >= 0; i++, j--) 
        if (board[i][j]) return false; 
    return true;
} 
bool solve(int c) { 
    if (c == N) return true;
    for (int r = 0; r < N; ++r) { 
        if (isSafe(r, c)) { 
            board[r][c] = 1; 
            if (solve(c + 1)) return true;
            board[r][c] = 0;
        } 
    } 
    return false;
} 
int main() { 
    if (solve(0)) { 
        for (int i = 0; i < N; ++i) { 
            for (int j = 0; j < N; ++j) 
                cout << (board[i][j] ? "  Q  " : "  .  ");
            cout << endl; 
        } 
    } else { 
        cout << "No solution";
    } 
    return 0; 
}
