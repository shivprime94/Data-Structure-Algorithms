#include <bits/stdc++.h>
using namespace std;
#define N 8
int mat[N][N];
//simple travelling that works for square matrix
int row[N] = {2, 1, -1, -2, -2, -1, 1, 2};
int col[N] = {1, 2, 2, 1, -1, -2, -2, -1};
bool isValid(int row, int column)
{
  return (row >= 0 && column >= 0 && row < N && column < N && mat[row][column] == -1);
}
bool go(int r, int c, int move)
{
  if (move == N * N)
    return true;
  int move_x, move_y;
  for (int k = 0; k < N; k++)
  {
    move_x = r + row[k];
    move_y = c + col[k];
    if (isValid(move_x, move_y))
    {
      mat[move_x][move_y] = move + 1; //storing the move-number in matrix
      if (go(move_x, move_y, move + 1) == 1)
        return true;
      else
        mat[move_x][move_y] = -1; //backtracking
    }
  }
  return false;
}
int main()
{

  memset(mat, -1, sizeof(mat));
  mat[0][0] = 1;
  if (go(0, 0, 1))
  {
    //calling recur function and print the path matrix
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
        cout << mat[i][j] << "  ";
      cout << endl;
    }
  }
  else
    cout << "Not possible\n";
  return 0;
}
