#include "bits/stdc++.h"
#include <ctime>
using namespace std;
const long long int INF = (long long)1e9;
const long long int CUT_OFF_DEPTH = 12;
time_t start_time;
int A[10][10];
int my_player;
int board[10][10];

int isValid(int r, int c){
    if(r >= 0 && c >= 0 && r < 10 && c < 10)
        return true;
    return false;
}

void turn_pieces(int me, int opp, int row, int col)
{
    if(isValid(row - 1, col) && board[row - 1][col] == opp && board[row][col] == me && isValid(row - 2, col) && board[row - 2][col] == me)
    {
        board[row - 1][col] = me;
    }
    if(isValid(row + 1, col) && board[row + 1][col] == opp && board[row][col] == me && isValid(row + 2, col) && board[row + 2][col] == me)
    {
        board[row + 1][col] = me;
    }
    if(isValid(row, col + 1) && board[row][col + 1] == opp && board[row][col] == me && isValid(row, col + 2) && board[row][col + 2] == me)
    {
        board[row][col + 1] = me;
    }
    if(isValid(row, col - 1) && board[row][col - 1] == opp && board[row][col] == 0 && isValid(row, col - 2) && board[row][col - 2] == me)
    {
        board[row][col - 1] = me;
    }
    if(isValid(row - 1, col - 1) && board[row - 1][col - 1] == opp && board[row][col] == me && isValid(row - 2, col - 2) && board[row - 2][col - 2] == me)
    {
        board[row - 1][col - 1] = me;
    }
    if(isValid(row + 1, col + 1) && board[row + 1][col + 1] == opp && board[row][col] == me && isValid(row + 2, col + 2) && board[row + 2][col + 2] == me)
    {
        board[row + 1][col + 1] = me;
    }
    if(isValid(row - 1, col + 1) && board[row - 1][col + 1] == opp && board[row][col] == me && isValid(row - 2, col + 2) && board[row - 2][col + 2] == me)
    {
        board[row - 1][col + 1] = me;
    }
    if(isValid(row + 1, col - 1) && board[row + 1][col - 1] == opp && board[row][col] == me && isValid(row + 2, col - 2) && board[row + 2][col - 2] == me)
    {
        board[row + 1][col - 1] = me;
    }
    
    if(isValid(row - 1, col) && board[row - 1][col] == opp && board[row][col] == me && isValid(row + 1, col) && board[row + 1][col] == opp)
    {
        board[row][col] = opp;
    }
    if(isValid(row, col - 1) && board[row][col - 1] == opp && board[row][col] == me && isValid(row, col + 1) && board[row][col + 1] == opp)
        board[row][col] = opp;
    if(isValid(row - 1, col - 1) && board[row - 1][col - 1] == opp && board[row][col] == me && isValid(row + 1, col + 1) && board[row + 1][col + 1] == opp)
        board[row][col] = opp;
    if(isValid(row - 1, col + 1) && board[row - 1][col + 1] == opp && board[row][col] == me && isValid(row + 1, col - 1) && board[row + 1][col - 1] == opp)
        board[row][col] = opp;
}

long double heuristic()
{
    int my = 0;
    int opp = 0;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j)
            if(board[i][j] == my_player)
                my++;
            else if(board[i][j] == 0)
                continue;
            else
                opp++;
    }
    if(my > opp)
        return my;
    else
        return -opp;
}

int get_marker(int turn)
{
    if(turn == 0)
        return my_player;
    else{
        if(my_player == 1)
            return 2;
        else
            return 1;
    }
}

bool check_validity(int me, int opp, int row, int col)
{
    if(isValid(row - 1, col) && board[row - 1][col] == opp && board[row][col] == 0 && isValid(row - 2, col) && board[row - 2][col] == me)
        return true;
    if(isValid(row + 1, col) && board[row + 1][col] == opp && board[row][col] == 0 && isValid(row + 2, col) && board[row + 2][col] == me)
        return true;
    if(isValid(row, col + 1) && board[row][col + 1] == opp && board[row][col] == 0 && isValid(row, col + 2) && board[row][col + 2] == me)
        return true;
    if(isValid(row, col - 1) && board[row][col - 1] == opp && board[row][col] == 0 && isValid(row, col - 2) && board[row][col - 2] == me)
        return true;
    
    if(isValid(row - 1, col - 1) && board[row - 1][col - 1] == opp && board[row][col] == 0 && isValid(row - 2, col - 2) && board[row - 2][col - 2] == me)
        return true;
    if(isValid(row + 1, col + 1) && board[row + 1][col + 1] == opp && board[row][col] == 0 && isValid(row + 2, col + 2) && board[row + 2][col + 2] == me)
        return true;
    if(isValid(row - 1, col + 1) && board[row - 1][col + 1] == opp && board[row][col] == 0 && isValid(row - 2, col + 2) && board[row - 2][col + 2] == me)
        return true;
    if(isValid(row + 1, col - 1) && board[row + 1][col - 1] == opp && board[row][col] == 0 && isValid(row + 2, col - 2) && board[row + 2][col - 2] == me)
        return true;
    
    if(isValid(row - 1, col) && board[row - 1][col] == opp && board[row][col] == 0 && isValid(row + 1, col) && board[row + 1][col] == opp)
        return true;
    if(isValid(row, col - 1) && board[row][col - 1] == opp && board[row][col] == 0 && isValid(row, col + 1) && board[row][col + 1] == opp)
        return true;
    if(isValid(row - 1, col - 1) && board[row - 1][col - 1] == opp && board[row][col] == 0 && isValid(row + 1, col + 1) && board[row + 1][col + 1] == opp)
        return true;
    if(isValid(row - 1, col + 1) && board[row - 1][col + 1] == opp && board[row][col] == 0 && isValid(row + 1, col - 1) && board[row + 1][col - 1] == opp)
        return true;
    
    return false;
}

pair <long long int, pair <int ,int> > dfs(int turn, int depth, long long alpha, long long beta)
{
    // Put constraint on time
    if(depth == CUT_OFF_DEPTH){
        return {heuristic(), {-1, -1}};
    }
    if(turn == 0){
        // Objective is to maximize score
        long long bestVal = -INF;
        pair <int, int> best_move = {-1, -1};
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                int old_board[10][10];
                for(int k = 0; k < 10; ++k)
                    for(int l = 0; l < 10; ++l)
                        old_board[k][l] = board[k][l];
                // Check if possible to place marker
                if(check_validity(get_marker(turn), get_marker(1 - turn), i, j))
                {    // Place marker
                    board[i][j] = get_marker(turn);
                    turn_pieces(get_marker(turn), get_marker(1 - turn), i, j);
                }
                else
                    continue;
                
                long long store = dfs(1 - turn, depth + 1, alpha, beta).first;
                if(store > bestVal){
                    bestVal = store;
                    best_move = {i, j};
                }
                // Undo move
                for(int k = 0; k < 10; ++k)
                    for(int l = 0; l < 10; ++l)
                        board[k][l] = old_board[k][l];
                alpha = max(alpha, bestVal);
                if(beta <= alpha)
                    break;
                time_t curr_time = time(NULL);
                if((curr_time - start_time) >= 4)
                    return {bestVal, best_move};            
            }
            time_t curr_time = time(NULL);
            if((curr_time - start_time) >= 4)
                return {bestVal, best_move};
            if(beta <= alpha)
                break;
        }
        if(bestVal == -INF)
            bestVal = heuristic();
        return {bestVal, best_move};
    }
    else{
        // Objective is to minimize score
        long long bestVal = INF;
        pair <int, int> best_move = {-1, -1};
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){

                int old_board[10][10];
                for(int k = 0; k < 10; ++k)
                    for(int l = 0; l < 10; ++l)
                        old_board[k][l] = board[k][l];
                // Check if possible to place marker
                if(check_validity(get_marker(turn), get_marker(1 - turn), i, j))
                {    // Place marker
                    board[i][j] = get_marker(turn);
                    turn_pieces(get_marker(turn), get_marker(1 - turn), i, j);
                }
                else
                    continue;
                
                long long store = dfs(1 - turn, depth + 1, alpha, beta).first;
                if(store < bestVal){
                    bestVal = store;
                    best_move = {i, j};
                }
                
                // Undo move
                for(int k = 0; k < 10; ++k)
                    for(int l = 0; l < 10; ++l)
                        board[k][l] = old_board[k][l];
                beta = min(beta, bestVal);
                if(beta <= alpha)
                    break;
                time_t curr_time = time(NULL);
                if((curr_time - start_time) >= 4)
                    return {bestVal, best_move};
            }
            if(beta <= alpha)
                break;
            time_t curr_time = time(NULL);
            if((curr_time - start_time) >= 4)
                return {bestVal, best_move};
        }
        if(bestVal == INF)
            bestVal = heuristic();
        return {bestVal, best_move};
    }
}

int main()
{

    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    start_time = time(NULL);
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            cin >> A[i][j];
    
    // My player number
    cin >> my_player;

    // Make a copy of board
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j)
            board[i][j] = A[i][j];
    }
    pair <int, int> tmp = dfs(0, 0, -INF, INF).second;
    cout << tmp.first << endl;
    cout << tmp.second << endl;
    return 0;
}