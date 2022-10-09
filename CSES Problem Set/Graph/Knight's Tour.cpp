/* Author : G Pala Venki Reddy */

/* Problem Description */

/*
    Given a starting position of a knight on an 8×8 chessboard, 
    your task is to find a sequence of moves such that it visits every square exactly once.

    On each move, the knight may either move two steps horizontally and one step vertically, 
    or one step horizontally and two steps vertically.

*/

/*
    Input: 
    The only line has two integers x and y: the knight's starting position.

    Output:
    Print a grid that shows how the knight moves (according to the example). You can print any valid solution.

    Constraints:
    1 ≤ x, y ≤8
*/

/*
    Example test case:

    Sample Input:
    2 1

    Sample Output:
    8 1 10 13 6 3 20 17
    11 14 7 2 19 16 23 4
    26 9 12 15 24 5 18 21
    49 58 25 28 51 22 33 30
    40 27 50 59 32 29 52 35
    57 48 41 44 37 34 31 62
    42 39 46 55 60 63 36 53
    47 56 43 38 45 54 61 64

*/

/* --------------Solution -------------------*/

#include <bits/stdc++.h>

using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lli long long int

vector<int> r = {-1, -2, -2, -1, 1, 2, 1, 2};
vector<int> c = {-2, -1, 1, 2, -2, -1, 2, 1};
int n = 8;
vector<vector<int>> grid(n, vector<int> (n, -1));

vector<pair<int, int>> possibleMoves(vector<vector<int>> grid, int row, int col)
{
    vector<pair<int, int>> moves;
    for(int i = 0; i < 8; i++)
    {
        int cr = row + r[i];
        int cc = col + c[i];
        if(cr < 0 || cr >= 8 || cc < 0 || cc >= 8)
        {
            continue;
        }
        if(grid[cr][cc] != -1)
        {
            continue;
        }
        moves.push_back({cr, cc});
    }

    return moves;
}


int main()
{
    fastio();

    int x, y;
    cin >> x >> y;
    x--; y--;
    int move = 1;
    /* using backtracking -> in worst case scenerio, time complexity is O(8^(n^2)) which is too large */ 
    /* so we will use (Warnsdorff's rules) condition that move the knight to cell which is valid and also possesss less moves compared to other valid moves */

    int curr_row = y;
    int curr_col = x;
    while(true)
    {
        if(move == 65)
        {
            break;
        }
        grid[curr_row][curr_col] = move;
        move++;
        vector<pair<int, int>> pos = possibleMoves(grid, curr_row, curr_col);
        int min_moves = 9;
        pair<int, int> p;
        for(auto x: pos)
        {
            vector<pair<int, int>> temp = possibleMoves(grid, x.first, x.second);
            if((int)temp.size() <= min_moves)
            {
                p = {x.first, x.second};
                min_moves = temp.size();   
            }
        }
        curr_row = p.first;
        curr_col = p.second;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}