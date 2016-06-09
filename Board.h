#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

const int POPULATED_PORTION = 40;
const int POPULATION_DENSITY = 80;

class Board {
private:
  int SIZE;
  vector<vector<int>> the_board;
  vector<vector<int>> temp_board;
public:
  Board(int size = 80){
    SIZE = size;
    int curr_rand = -1;
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
      vector<int> one_row;
      for (int j = 0; j < SIZE; j++) {
        // if (i == 0 || i == SIZE - 1 || j == 0 || j == SIZE - 1) one_row.push_back(0);
        if ((i > (SIZE/POPULATED_PORTION) && i < (SIZE - (SIZE / POPULATED_PORTION)))
          && (j > (SIZE/POPULATED_PORTION) && j < (SIZE - (SIZE / POPULATED_PORTION)))) {
        // if (i > 2 && i < 78 && j > 2 && j < 78) {
          curr_rand = rand()%POPULATION_DENSITY;
          if (curr_rand < 50) one_row.push_back(0);
          else one_row.push_back(1);
        }
        else one_row.push_back(rand()%2);
        // the_board[i][j] = rand() % 2;
        // if (i == 0 || i == SIZE - 1) the_board[i][j] = 0;
        // if (j == 0 || j == SIZE - 1) the_board[i][j] = 0;
      }
      the_board.push_back(one_row);
    }
  }
  ~Board() {

  }
  bool checkSquare(int i, int j) {
    if (i < 0) i = SIZE - 1;
    else if (i >= SIZE) i = 0;
    if (j < 0) j = SIZE - 1;
    else if (j >= SIZE) j = 0;
    if (temp_board[i][j]) return true;
    return false;
  }
  int calculateNeighbors(int i, int j) {
    int total = 0;
    if (checkSquare(i-1,j-1)) total++;
    if (checkSquare(i-1,j)) total++;
    if (checkSquare(i-1,j+1)) total++;
    if (checkSquare(i,j-1)) total++;
    if (checkSquare(i,j+1)) total++;
    if (checkSquare(i+1,j-1)) total++;
    if (checkSquare(i+1,j)) total++;
    if (checkSquare(i+1,j+1)) total++;
    return total;
  }
  void copyArray() {
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        temp_board[i][j] = the_board[i][j];
      }
    }
  }
  void oneIteration() {
    // copyArray();
    temp_board = the_board;
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        // If a square is currently alive, then it can only continue to live on the next turn if two or three of its neighbors are alive
        if (temp_board[i][j]) {
          int neighbors = calculateNeighbors(i, j);
          if (neighbors != 2 && neighbors != 3) the_board[i][j] = false;
        }
        // If a square is currently dead, then if there are three live neighbors it becomes alive
        else if (!temp_board[i][j]) {
          int neighbors = calculateNeighbors(i, j);
          if (neighbors == 3) the_board[i][j] = true;
        }
      }
    }
  }
  void print() {
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        if (the_board[i][j]) cout << "\033[1;31m" << 1 << "\033[0m" << " ";
        else cout << "\033[1;34m" << 0 << "\033[0m" << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
};