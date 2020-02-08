#include <bits/stdc++.h>
using namespace std;
const int board_size = 10;

pair<int, int> solution;

int weight_mat[board_size][board_size] = {{120, -20,  20,   5,   5,   5,   5,  20, -20, 120},{-20, -40,  -5,  -5,  -5,  -5,  -5,  -5, -40, -20},{20,  -5,  15,  15,   3,   3,  15,  15,  -5,  20},{5,  -5,   3,   3,   3,   3,   3,   3,  -5,   5},{5,  -5,   3,   3,   3,   3,   3,   3,  -5,   5},{5,  -5,   3,   3,   3,   3,   3,   3,  -5,   5},{5,  -5,   3,   3,   3,   3,   3,   3,  -5,   5},{20,  -5,  15,  15,   3,   3,  15,  15,  -5,  20},{-20, -40,  -5,  -5,  -5,  -5,  -5,  -5, -40, -20},{120, -20,  20,   5,   5,   5,   5,  20, -20, 120}};

vector<pair<int, int> > get_valid_moves(int board[10][10], int player_num) {
    vector<pair<int, int> > valid_moves;

    for(int i=0; i<10; ++i)
    {
        for(int j=0; j<10; ++j)
        {
            if(board[i][j] == 0)
            {
                // Up
                for(int k=i-1; k>=0 && board[k][j]; --k)
                {
                    if(board[k][j] == player_num) 
                    {
                        if(k != i-1) valid_moves.push_back(make_pair(i,j));
                        break;
                    }
                }

                // Down
                for(int k=i+1; k<10 && board[k][j]; ++k)
                {
                    if(board[k][j] == player_num) 
                    {
                        if(k != i+1) valid_moves.push_back(make_pair(i,j));
                        break;
                    }
                }

                // Left
                for(int k=j-1; k>=0 && board[i][k]; --k)
                {
                    if(board[i][k] == player_num) 
                    {
                        if(k != j-1) valid_moves.push_back(make_pair(i,j));
                        break;
                    }
                }

                // Right
                for(int k=j+1; k<10 && board[i][k]; ++k)
                {
                    if(board[i][k] == player_num) 
                    {
                        if(k != j+1) valid_moves.push_back(make_pair(i,j));
                        break;
                    }
                }

                // Diagonal left top
                for(int k=i-1, m=j-1; k>=0 && m>=0 && board[k][m]; --k, --m)
                {
                    if(board[k][m] == player_num) 
                    {
                        if(k != i-1 && m != j-1) valid_moves.push_back(make_pair(i,j));
                        break;
                    }
                }

                // Diagonal right top
                for(int k=i-1, m=j+1; k>=0 && m<10 && board[k][m]; --k, ++m)
                {
                    if(board[k][m] == player_num) 
                    {
                        if(k != i-1 && m != j+1) valid_moves.push_back(make_pair(i,j));
                        break;
                    }
                }

                // Diagonal left bottom
                for(int k=i+1, m=j-1; k<10 && m>=0 && board[k][m]; ++k, --m)
                {
                    if(board[k][m] == player_num) 
                    {
                        if(k != i+1 && m != j-1) valid_moves.push_back(make_pair(i,j));
                        break;
                    }
                }

                // Diagonal right bottom
                for(int k=i+1, m=j+1; k<10 && m<10 && board[k][m]; ++k, ++m)
                {
                    if(board[k][m] == player_num) 
                    {
                        if(k != i+1 && m != j+1) valid_moves.push_back(make_pair(i,j));
                        break;
                    }
                }
            }
        }
    }

    return valid_moves;
}

int get_value(int board[10][10]){
    int i = 0, j = 0, val = 0;
    for(;i<board_size;++i){
        for(j=0;j<board_size;++j){
            if(board[i][j] == 1) val += weight_mat[i][j];
            else if(board[i][j]) val -= weight_mat[i][j];
        }
    }
}

void copy(int board[board_size][board_size], int copyto[board_size][board_size], pair<int,int> cur, int ply){

    for(int i=0; i<board_size; ++i){
        for(int j=0; j<board_size; ++j){
            copyto[i][j] = board[i][j];
        }
    }

    int x = cur.first, y = cur.second;
    copyto[x][y] = ply;

    // Up
    for(int i=x-1; i>=0 && board[i][y]; --i) {
        if(board[i][y] == ply) {
            if(i != x-1) {
                for(int k=x-1; k >= i; --k) {
                    copyto[k][y] = ply;
                }
            }
            break;
        }
    }

    // Down
    for(int i=x+1; i<board_size && board[i][y]; ++i) {
        if(board[i][y] == ply) {
            if(i != x+1) {
                for(int k=x+1; k <= i; ++k) {
                    copyto[k][y] = ply;
                }
            }
            break;
        }
    }

    // Left
    for(int j=y-1; j>=0 && board[x][j]; --j) {
        if(board[x][j] == ply) {
            if(j != y-1) {
                for(int k=y-1; k >= j; --k) {
                    copyto[x][k] = ply;
                }
            }
            break;
        }
    }

    // Right
    for(int j=y+1; j<board_size && board[x][j]; ++j) {
        if(board[x][j] == ply) {
            if(j != y+1) {
                for(int k=y+1; k <= j; ++k) {
                    copyto[x][k] = ply;
                }
            }
            break;
        }
    }
    
    // Diagonal left top
    for(int i=x-1, j=y-1; i>=0 && j>=0 && board[i][j]; --i, --j) {
        if(board[i][j] == ply) {
            if(i != x-1 && j != y-1) {
                for(int k=x-1, m=y-1; k>=i, m>=j; --k, --m) copyto[k][m] = ply;
            }
            break;
        }
    }

    // Diagonal right top
    for(int i=x-1, j=y+1; i>=0 && j<10 && board[i][j]; --i, ++j) {
        if(board[i][j] == ply) {
            if(i != x-1 && j != y+1) {
                for(int k=x-1, m=y+1; k>=i, m<=j; --k, ++m) copyto[k][m] = ply;
            }
            break;
        }
    }

    // Diagonal left bottom
    for(int i=x+1, j=y-1; i<10 && j>=0 && board[i][j]; ++i, --j) {
        if(board[i][j] == ply) {
            if(i != x+1 && j != y-1) {
                for(int k=x+1, m=y-1; k<=i, m>=j; ++k, --m) copyto[k][m] = ply;
            }
            break;
        }
    }

    // Diagonal right bottom
    for(int i=x+1, j=y+1; i<10 && j<10 && board[i][j]; ++i, ++j) {
        if(board[i][j] == ply) {
            if(i != x+1 && j != y+1) {
                for(int k=x+1, m=y+1; k<=i, m<=j; ++k, ++m) copyto[k][m] = ply;
            }
            break;
        }
    }
}

int minimax(int board[board_size][board_size], int ply, int alpha, int beta, int dep, int max_dep){
    vector<pair<int, int> > valid_moves = get_valid_moves(board, ply);
    pair<int, int> curr;
    int min_val = INT_MIN, max_val = INT_MAX, val = 0;
    int copyto[board_size][board_size];

    if(valid_moves.empty()){
        if(ply == 1){
            return min_val + 1;
        }
        else{
            return max_val - 1;
        }
    }

    if(dep == max_dep){
        if(ply == 1){
            return get_value(board) + valid_moves.size() - get_valid_moves(board, 2).size();
        }
        return get_value(board)  - valid_moves.size() + - get_valid_moves(board, 1).size();
    }

    if(ply == 1){
        for(vector<pair<int,int> >::size_type i = 0; i != valid_moves.size(); ++i){
            curr = valid_moves[i];
            copy(board, copyto, curr, ply);
            val = minimax(copyto, 2, alpha, beta, dep+1, max_dep);
            if(val > min_val){
                min_val = val;
                if(dep == 0){
                    solution = curr;
                }
            }
            alpha = max(alpha, min_val);
            if(beta<=alpha)
                return min_val;
        }
    }
    else{
        for(vector<pair<int,int> >::size_type i = 0; i != valid_moves.size(); ++i){
            curr = valid_moves[i];
            copy(board, copyto, curr, ply);
            val = minimax(copyto, 1, alpha, beta, dep+1, max_dep);
            if(val < max_val){
                min_val = val;
                if(dep == 0){
                    solution = curr;
                }
            }
            beta = min(alpha, max_val);
            if(beta<=alpha)
                return min_val;
        }
    }
    return val;
}


int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int board[board_size][board_size], ply, i=0, j=0;

    for(;i<board_size;++i){
        for(j=0;j<board_size;++j){
            cin >> board[i][j];
        }
    }

    cin >> ply;

    int val = minimax(board, ply, INT_MIN, INT_MAX, 0, 5);

    cout << solution.first << "\n" << solution.second << endl;

    return 0;
}