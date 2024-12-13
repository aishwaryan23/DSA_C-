#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
bool isSafe(vector<vector<char>>board,int row, int col,char dig){
    //horizontal
    for(int i=0;i<9;i++){
        if(board[row][i]==dig){
            return false;
        }
    }

    //vertical
    for(int j=0;j<9;j++){
        if(board[j][col]==dig){
            return false;
        }
    }
    
    //3*3 grid
    int srow = (row/3)*3;
    int scol = (col/3)*3;
    for(int i=srow;i<=srow+2;i++){
        for(int j=scol;j<=scol+2;j++){
            if(board[i][j]==dig){
                return false;
            }
        }
    }
    return true;
}
bool ss(vector<vector<char>>board,int row, int col){
    if(row==9){
        return true;
    }
    int nextRow=row,nextCol=col+1;
    if(nextCol==9){
        nextRow=row+1;
        nextCol=0;
    }
    if(board[row][col]!='.')
    {
        return ss(board,nextRow,nextCol);
    }

    for(char dig='1';dig<='9';dig++){
        if(isSafe(board,row,col,dig)){
            board[row][col]=dig;
            if(ss(board,nextRow,nextCol))
                return true;
            board[row][col]='.';
        }
    }
    return false;
}

void solve(vector<vector<char>>& board){
    ss(board,0,0);
}

int main() {
    // Input grid (0 represents empty cells)
    vector<vector<char>> board = {
        {'5', '3', ',', ',', '7', ',', ',', ',', ','},
        {'6', ',', ',', '1', '9', '5', ',', ',', ','},
        {',', '9', '8', ',', ',', ',', ',', '6', ','},
        {'8', ',', ',', ',', '6', ',', ',', ',', '3'},
        {'4', ',', ',', '8', ',', '3', ',', ',', '1'},
        {'7', ',', ',', ',', '2', ',', ',', ',', '6'},
        {',', '6', ',', ',', ',', ',', '2', '8', ','},
        {',', ',', ',', '4', '1', '9', ',', ',', '5'},
        {',', ',', ',', ',', '8', ',', ',', '7', '9'}
    };

    solve(board);
    return 0;
}