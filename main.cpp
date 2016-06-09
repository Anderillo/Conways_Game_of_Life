#include <iostream>
#include "Board.h"

using namespace std;

int main() {
  // cout << "Size of board: ";
  // int size;
  // cin >> size;
  // cout << "Speed: ";
  // int speed;
  // cin >> speed;
  Board board;
  // if (size != -1) board = Board(size);
  while (true) {
    board.print();
    for (int i = 0; i < 1; i++) {
      board.oneIteration();
    }
    cin.ignore();
  }

  return 0;
}