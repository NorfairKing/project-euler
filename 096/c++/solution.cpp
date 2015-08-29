#include <iostream>
#include "lib/src/board.h"
#include "lib/src/constants.h"

int solve();

#ifndef TESTING
int main () {
  std::cout << solve() << std::endl;
}
#endif

Board readBoard() {
  Board board;
  char buf;
  for (int x = 0; x < SIZE; ++x) {
    for (int y = 0; y < SIZE; ++y) {
      std::cin.get(buf);
      board.setTile(x, y, buf - '0');
    }
    std::cin.get(); // Get newline
  }
  return board;
}

int solve() {
  int n, p;
  std::cin >> n;
  std::cin >> p;
  std::cin.get(); // Get newline
  int sum = 0;
  for (int i = 0; i < p; ++i) {
    std::cin.ignore(256, '\n'); // Ignore the line with the board number.
    Board board = readBoard();
    board.solve();
    for (int j = 0; j < n; ++j) {
      sum += board.getTile(0,j) * pow(10, n-j-1);
    }
  }
  return sum;
}

