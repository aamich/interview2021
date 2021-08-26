/*

We have a two-dimensional board game involving snakes.  The board has two types of squares on it: +'s represent impassable squares where snakes cannot go, and 0's represent squares through which snakes can move.  Snakes can only enter on the edges of the board, and each snake can move in only one direction.  We'd like to find the places where a snake can pass through the entire board, moving in a straight line.

Here is an example board:

    col-->        0  1  2  3  4  5  6
               +----------------------
    row      0 |  +  +  +  0  +  0  0
     |       1 |  0  0  0  0  0  0  0
     |       2 |  0  0  +  0  0  0  0
     v       3 |  0  0  0  0  +  0  0
             4 |  +  +  +  0  0  0  +

Write a function that takes a rectangular board with only +'s and 0's, and returns two collections:

* one containing all of the row numbers whose row is completely passable by snakes, and  
* the other containing all of the column numbers where the column is completely passable by snakes.

Complexity Analysis:

r: number of rows in the board
c: number of columns in the board




snake_case version of the inputs and function calls:
straight_board_1 = [['+', '+', '+', '0', '+', '0', '0'],
                    ['0', '0', '0', '0', '0', '0', '0'],
                    ['0', '0', '+', '0', '0', '0', '0'],
                    ['0', '0', '0', '0', '+', '0', '0'],
                    ['+', '+', '+', '0', '0', '0', '+']]

find_passable_lanes(straight_board_1) # = Rows: [1], Columns: [3, 5]

straight_board_2 = [['+', '+', '+', '0', '+', '0', '0'],
                    ['0', '0', '0', '0', '0', '+', '0'],
                    ['0', '0', '+', '0', '0', '0', '0'],
                    ['0', '0', '0', '0', '+', '0', '0'],
                    ['+', '+', '+', '0', '0', '0', '+']]

find_passable_lanes(straight_board_2) # = Rows: [], Columns: [3]

straight_board_3 = [['+', '+', '+', '0', '+', '0', '0'],
                    ['0', '0', '0', '0', '0', '0', '0'],
                    ['0', '0', '+', '+', '0', '+', '0'],
                    ['0', '0', '0', '0', '+', '0', '0'],
                    ['+', '+', '+', '0', '0', '0', '+']]

find_passable_lanes(straight_board_3) # = Rows: [1], Columns: []

straight_board_4 = [['+']]

find_passable_lanes(straight_board_4) # = Rows: [], Columns: []





*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ways(const vector<vector<char>>& vv) {
  vector<int> rows;
  for(int r = 0; r < vv.size(); ++r) {
    int sum = 0;
    for(auto it : vv[r])
      sum += it - '0';
    if(sum == 0)
      rows.push_back(r);
  }
  vector<int> cols;
  int nc = vv[0].size();
  for(int c = 0; c < nc; ++c) {
    int  sum = 0;
    for(int r = 0; r < vv.size(); ++ r)
      sum += vv[r][c] - '0';
    if(sum == 0)
      cols.push_back(c);
  }
  
  
  vector<vector<int>> res;
  res.push_back(rows);
  res.push_back(cols);
  return res;
};


int main() {
    vector<vector<char>> straightBoard1 = {
      {'+', '+', '+', '0', '+', '0', '0'},
      {'0', '0', '0', '0', '0', '0', '0'},
      {'0', '0', '+', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '+', '0', '0'},
      {'+', '+', '+', '0', '0', '0', '+'}};

  vector<vector<char>> straightBoard2 = {
      {'+', '+', '+', '0', '+', '0', '0'},
      {'0', '0', '0', '0', '0', '+', '0'},
      {'0', '0', '+', '0', '0', '0', '0'},
      {'0', '0', '0', '0', '+', '0', '0'},
      {'+', '+', '+', '0', '0', '0', '+'}};

  vector<vector<char>> straightBoard3 = {
      {'+', '+', '+', '0', '+', '0', '0'},
      {'0', '0', '0', '0', '0', '0', '0'},
      {'0', '0', '+', '+', '0', '+', '0'},
      {'0', '0', '0', '0', '+', '0', '0'},
      {'+', '+', '+', '0', '0', '0', '+'}};

  vector<vector<char>> straightBoard4 = { 
      {'+'}}; 

  auto res = ways(straightBoard1);
  
  
  // find_passable_lanes(straight_board_1) # = Rows: [1], Columns: [3, 5]
  cout << "Rows: [";
  for(int i = 0; i < res[0].size(); ++i)
    cout << res[0][i];
  cout << "], Columns: [";
  for(int i = 0; i < res[1].size(); ++i)
    cout << res[1][i] << ",";
  cout << "]";
  cout << endl;

    res = ways(straightBoard2);
    cout << "Rows: [";
  for(int i = 0; i < res[0].size(); ++i)
    cout << res[0][i];
  cout << "], Columns: [";
  for(int i = 0; i < res[1].size(); ++i)
    cout << res[1][i] << ",";
  cout << "]";  
  cout << endl;
  
  res = ways(straightBoard3);
    cout << "Rows: [";
  for(int i = 0; i < res[0].size(); ++i)
    cout << res[0][i];
  cout << "], Columns: [";
  for(int i = 0; i < res[1].size(); ++i)
    cout << res[1][i] << ",";
  cout << "]";
  cout << endl;
  
  res = ways(straightBoard4);
    cout << "Rows: [";
  for(int i = 0; i < res[0].size(); ++i)
    cout << res[0][i];
  cout << "], Columns: [";
  for(int i = 0; i < res[1].size(); ++i)
    cout << res[1][i] << ",";
  cout << "]";
  
  
  return 0;
}
