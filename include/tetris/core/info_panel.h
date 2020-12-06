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

#pragma once

#include <tetris/core/shape.h>

#include <vector>

namespace info {
class NextShape {
 public:
  // standard board size is 10 wide and 20 high
  explicit NextShape(int height = 7, int width = 5);  // constructor

  // setters and getters
  void save_state();
  int height(bool incl_boarder = true);
  int width(bool incl_boarder = true);
  std::vector<std::vector<char>> get_board();
  std::vector<std::vector<int>> get_color_board();

  // drawing
  void draw_shape(Shape *shape, const int &rotation);

 private:
  int _width;   // nun cols for playing field
  int _height;  // num rows for playing field
  std::vector<std::vector<char>> empty_board;
  std::vector<std::vector<char>> fixed_board;  // holds fixed position items
  std::vector<std::vector<int>> color_board;   // holds ansi color code
  std::vector<std::vector<char>> board;
  std::vector<char> blank_mid_row;
  std::vector<int> blank_color_row;

  void initialize_board();
  void set_board(std::vector<std::vector<char>> b);
  void reset_board();
};
}  // namespace info
