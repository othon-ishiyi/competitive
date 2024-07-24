#include <bits/stdc++.h>
#define ll long long
#define vii vector<pair<int, int>>

using namespace std;

// I forgot that when there is a piece in a line range it blocks the attack. Hence the answer is wrong.
void put_piece(char piece, int row, int col, vector<vector<bool>> &board){
    if(piece == 'k' || piece == 'K') {
        for(int i = row-1; i <= row+1; i++){
            for(int j = col-1; j <=col+1; j++){
                if(i >= 0 && j >= 0 && i < 8 && j < 8)
                    board[i][j] = true;
            }
        }
    }
    if(piece == 'b' || piece == 'B') {
        board[row][col] = true;

        for(int i = 1; i <= 7; i++){
            if(row+i < 8 & col+i < 8) {
                board[row+i][col+i] = true;
            }
            if(row-i > 0 & col+i < 8) {
                board[row-i][col+i] = true;
            }
            if(row-i > 0 & col-i > 0) {
                board[row-i][col-i] = true;
            }
            if(row+i < 8 & col-i > 0) {
                board[row+i][col-i] = true;
            }
        }
    }
    if(piece == 'r' || piece =='R') {
        for(int i = 0; i <= 7; i++){
            board[i][col] = true;
            board[row][i] = true;
        }
    }
    if(piece == 'q' || piece =='Q') {
        for(int i = 0; i <= 7; i++){
            board[i][col] = true;
            board[row][i] = true;
        }
        for(int i = 1; i <= 7; i++){
            if(row+i < 8 & col+i < 8) {
                board[row+i][col+i] = true;
            }
            if(row-i > 0 & col+i < 8) {
                board[row-i][col+i] = true;
            }
            if(row-i > 0 & col-i > 0) {
                board[row-i][col-i] = true;
            }
            if(row+i < 8 & col-i > 0) {
                board[row+i][col-i] = true;
            }
        }
    }
    if(piece == 'n' || piece == 'N') {
        vii moves = {{2,1}, {1,2}, {-2,-1}, {-1,-2}, {2,-1}, {-2, 1}, {1, -2}, {-1, 2}};
        board[row][col] = true;

        for(auto p: moves) {
            if(row+p.first < 8 && col+p.second < 8 && row+p.first >= 0 && col+p.second >= 0) {
                board[row+p.first][col+p.second] = true;
            }
        }
    }
    if(piece == 'p') {
        if(col < 7)
            board[row-1][col+1] = true;
        if(col > 0)
            board[row-1][col-1] = true;
        board[row][col] = true;
    }
    if(piece == 'P') {
        if(col < 7)
            board[row+1][col+1] = true;
        if(col > 0)
            board[row+1][col-1] = true;
        board[row][col] = true;
    }
}


int main() {
    string sentence, s;
    while(getline(cin, sentence)) {
        vector<vector<bool>> board(8, vector<bool>(8, false));
        stringstream ss(sentence);
        int row = 7;
        while(getline(ss, s, '/')) {
            int col = 0;
            for(char c: s){
                if(isdigit(c))
                    col += c - '0';
                else {
                    put_piece(c, row, col++, board);
                }
            }
            row--;
        }

        int ans = 0;

        for(auto v: board){
            for(auto u:v){
                if(!u)
                    ans++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}