#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//void changeO(int x, int y, vector<vector<char> >&board) {
    //if (x<0 || y<0) {
        //return;
    //}
    //if (x >= board.size() || y >= board[0].size()) {
        //return;
    //}
    //if (board[x][y] == 'O') {
        //board[x][y] = '$';
        //changeO(x-1, y, board);
        //changeO(x+1, y, board);
        //changeO(x, y-1, board);
        //changeO(x, y+1, board);
    //}
//}

void changeO(int x, int y, vector<vector<char> >&board, stack<pair<int, int> > &point_s) {
    if (x<0 || y<0) {
        return;
    }
    if (x >= board.size() || y >= board[0].size()) {
        return;
    }
    if (board[x][y] == 'O') {
        board[x][y] = '$';
        point_s.push(make_pair(x-1, y));
        point_s.push(make_pair(x+1, y));
        point_s.push(make_pair(x, y-1));
        point_s.push(make_pair(x, y+1));
    }
}
void solve(vector<vector<char>> &board) {
    int rows = board.size();
    if (rows == 0) {
        return;
    }
    int cols = board[0].size();
    if (cols == 0) {
        return;
    }
    pair<int, int> tmp_pair;
    stack<pair<int, int> > point_s;
    //find left,top,right,bottom's O, and change it to $
    //these Os should retained.
    //other Os should be changed to #
    int i, j;
    //left
    for (i = 0; i < rows; i++) {
        if (board[i][0] == 'O') {
            point_s.push(make_pair(i,0));
            while (!point_s.empty()) {
                tmp_pair = point_s.top();
                point_s.pop();
                changeO(tmp_pair.first, tmp_pair.second, board, point_s);
            }
        }
    }
    //top
    for (i = 1; i < cols; i++) {
        if (board[0][i] == 'O') {
            point_s.push(make_pair(0,i));
            while (!point_s.empty()) {
                tmp_pair = point_s.top();
                point_s.pop();
                changeO(tmp_pair.first, tmp_pair.second, board, point_s);
            }
        }
    }
    //right
    for (i = 1; i < rows; i++) {
        if (board[i][cols-1] == 'O') {
            point_s.push(make_pair(i,cols-1));
            while (!point_s.empty()) {
                tmp_pair = point_s.top();
                point_s.pop();
                changeO(tmp_pair.first, tmp_pair.second, board, point_s);
            }
        }
    }
    //bottom
    for (i = 1; i < cols-1; i++) {
        if (board[rows-1][i] == 'O') {
            point_s.push(make_pair(rows-1,i));
            while (!point_s.empty()) {
                tmp_pair = point_s.top();
                point_s.pop();
                changeO(tmp_pair.first, tmp_pair.second, board, point_s);
            }
        }
    }
    //change Os to Xs
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
    //restore
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (board[i][j] == '$') {
                board[i][j] = 'O';
            }
        }
    }
}

int main() {
    vector<char> tmp;
    vector<vector<char> > board;
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    board.push_back(tmp);
    tmp.clear();
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('O');
    board.push_back(tmp);
    tmp.clear();
    tmp.push_back('X');
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('X');
    board.push_back(tmp);
    tmp.clear();
    tmp.push_back('O');
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('X');
    board.push_back(tmp);
    tmp.clear();
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    tmp.push_back('O');
    board.push_back(tmp);
    tmp.clear();
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('X');
    tmp.push_back('O');
    board.push_back(tmp);
    solve(board);
    int rows = board.size();
    int cols = board[0].size();
    int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
