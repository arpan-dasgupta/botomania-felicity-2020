/*
	Created by Rahul Goel.
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1000000007;
const int INF = 1000000000;

#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define vvpii vector<vector<pair<int, int>>>
#define pb push_back
#define f first
#define s second
#define mp make_pair

int mat[12][12], valid_move[12][12], me, opp, count_valid = 0, priority[12][12];

bool comp(const pii &a, const pii &b)
{
    if(priority[a.f][a.s] == priority[b.f][b.s])
        return valid_move[a.f][a.s] > valid_move[a.f][a.s];
    else
        return priority[a.f][a.s] > priority[b.f][b.s];
}

void take_input()
{
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            cin >> mat[i][j];
    cin >> me;
    opp = 1 ^ 2 ^ me;
}

bool check_north(int i, int j)
{
    if (mat[i - 1][j] == me)
        return true;
    else if (mat[i - 1][j] == 0 || mat[i - 1][j] == 5)
        return false;
    else
    {
        count_valid++;
        return check_north(i - 1, j);
    }
}

bool check_east(int i, int j)
{
    if (mat[i][j + 1] == me)
        return true;
    else if (mat[i][j + 1] == 0 || mat[i][j + 1] == 5)
        return false;
    else
    {
        count_valid++;
        return check_east(i, j + 1);
    }
}

bool check_south(int i, int j)
{
    if (mat[i + 1][j] == me)
        return true;
    else if (mat[i + 1][j] == 0 || mat[i + 1][j] == 5)
        return false;
    else
    {
        count_valid++;
        return check_south(i + 1, j);
    }
}

bool check_west(int i, int j)
{
    if (mat[i][j - 1] == me)
        return true;
    else if (mat[i][j - 1] == 0 || mat[i][j - 1] == 5)
        return false;
    else
    {
        count_valid++;
        return check_west(i, j - 1);
    }
}

bool check_north_west(int i, int j)
{
    if (mat[i - 1][j - 1] == me)
        return true;
    else if (mat[i - 1][j - 1] == 0 || mat[i - 1][j - 1] == 5)
        return false;
    else
    {
        count_valid++;
        return check_north_west(i - 1, j - 1);
    }
}

bool check_north_east(int i, int j)
{
    if (mat[i - 1][j + 1] == me)
        return true;
    else if (mat[i - 1][j + 1] == 0 || mat[i - 1][j + 1] == 5)
        return false;
    else
    {
        count_valid++;
        return check_north_east(i - 1, j + 1);
    }
}

bool check_south_east(int i, int j)
{
    if (mat[i + 1][j + 1] == me)
        return true;
    else if (mat[i + 1][j + 1] == 0 || mat[i + 1][j + 1] == 5)
        return false;
    else
    {
        count_valid++;
        return check_south_east(i + 1, j + 1);
    }
}

bool check_south_west(int i, int j)
{
    if (mat[i + 1][j - 1] == me)
        return true;
    else if (mat[i + 1][j - 1] == 0 || mat[i + 1][j - 1] == 5)
        return false;
    else
    {
        count_valid++;
        return check_south_west(i + 1, j - 1);
    }
}

void is_valid_move()
{
    memset(valid_move, 0, sizeof(valid_move));
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (mat[i][j] == 0)
            {
                count_valid = 0;
                if (mat[i - 1][j] == opp && check_north(i - 1, j))
                {
                    valid_move[i][j] += count_valid + 1;
                }
                count_valid = 0;
                if (mat[i][j + 1] == opp && check_east(i, j + 1))
                {
                    valid_move[i][j] += count_valid + 1;
                }
                count_valid = 0;
                if (mat[i + 1][j] == opp && check_south(i + 1, j))
                {
                    valid_move[i][j] += count_valid + 1;
                }
                count_valid = 0;
                if (mat[i][j - 1] == opp && check_west(i, j - 1))
                {
                    valid_move[i][j] += count_valid + 1;
                }

                count_valid = 0;
                if (mat[i - 1][j - 1] == opp && check_north_west(i - 1, j - 1))
                {
                    valid_move[i][j] += count_valid + 1;
                }
                count_valid = 0;
                if (mat[i - 1][j + 1] == opp && check_north_east(i - 1, j + 1))
                {
                    valid_move[i][j] += count_valid + 1;
                }
                count_valid = 0;
                if (mat[i + 1][j + 1] == opp && check_south_east(i + 1, j + 1))
                {
                    valid_move[i][j] += count_valid + 1;
                }
                count_valid = 0;
                if (mat[i + 1][j - 1] == opp && check_south_west(i + 1, j - 1))
                {
                    valid_move[i][j] += count_valid + 1;
                }
            }
        }
    }
}

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    // memset(mat, 1, sizeof(mat));
    // memset(priority, 0, sizeof(priority));

    for (int i = 0; i <= 11; i++)
    {
        for (int j = 0; j <= 11; j++)
            mat[i][j]=5;
    }

    for (int i = 0; i <= 11; i++)
    {
        for (int j = 0; j <= 11; j++)
            priority[i][j]=0;
    }

    priority[1][1] = priority[1][10] = priority[10][1] = priority[10][10] = 1000;
    priority[1][3] = priority[1][8] = priority[3][3] = priority[3][8] = priority[8][1] = priority[8][3] = priority[8][8] = priority[10][3] = priority[10][8] = 900;
    priority[3][3] = priority[3][8] = priority[8][3] = priority[8][8] = 800;
    priority[1][2] = priority[2][1] = priority[2][2] = 0;
    priority[1][9] = priority[2][9] = priority[2][10] = 0;
    priority[9][1] = priority[9][2] = priority[10][2] = 0;
    priority[10][9] = priority[9][9] = priority[9][10] = 0;

    take_input();
    is_valid_move();

    if (mat[1][1])
        priority[1][2] = priority[2][1] = priority[2][2] = 950;
    if (mat[1][10])
        priority[1][9] = priority[2][9] = priority[2][10] = 950;
    if (mat[10][1])
        priority[9][1] = priority[9][2] = priority[10][2] = 950;
    if (mat[1][1])
        priority[10][9] = priority[9][9] = priority[9][10] = 950;
    

    // for (int i = 1; i <= 10; i++)
    // {
    //     for (int j = 1; j <= 10; j++)
    //         cout << valid_move[i][j] << " ";
    //     cout << endl;
    // }

    vector<pii> out;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            if (valid_move[i][j])
                out.pb({i, j});

    if(out.empty())
    {
        cout << -1 << endl;
        cout << -1 << endl;
        return 0;
    }

    sort(out.begin(), out.end(), comp);
    cout << out[0].f - 1 << endl;
    cout << out[0].s - 1 << endl;
    return 0;
}