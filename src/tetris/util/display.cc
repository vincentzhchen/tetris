// Tetris console game.
// Copyright (C) 2020  Vincent Chen

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <tetris/util/display.h>

#include <iostream>
#include <vector>

namespace display {

void display_all(Board board, info::NextShape ns_panel) {
  std::vector<std::vector<char>> b = board.matrix();
  std::vector<std::vector<int>> cb = board.color_matrix();

  std::vector<std::vector<char>> ns = ns_panel.matrix();
  std::vector<std::vector<int>> cns = ns_panel.color_matrix();

  system("clear");
  for (int i = 0; i < board.height(); i++) {
    // display board
    for (int j = 0; j < board.width(); j++) {
      if ((b[i][j] == '[') || (b[i][j] == ']'))
        std::cout << "\033[1;" << cb[i][j] << "m" << b[i][j] << "\033[0m";
      else
        std::cout << b[i][j];
    }
    // display next shape
    if (i < ns_panel.height()) {
      for (int j = 0; j < ns_panel.width(); j++) {
        if ((ns[i][j] == '[') || (ns[i][j] == ']'))
          std::cout << "\033[1;" << cns[i][j] << "m" << ns[i][j] << "\033[0m";
        else
          std::cout << ns[i][j];
      }
    }

    std::cout << std::endl;
  }
}

}  // namespace display
