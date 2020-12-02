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

class Board {
 public:
  // standard board size is 10 wide and 20 high
  explicit Board(int height = 20, int width = 10);  // constructor
  int get_board_height();
  int get_board_width();
  void draw();
  void draw_shape(Shape *shape, int row, int col, int rotation);
  bool is_collide(Shape *shape, int row, int col, int rotation);
  void save_state();
  bool is_valid_board();
  std::vector<int> get_line(Shape *shape, int row, int col, int rotation);
  void draw_line(std::vector<int> row);
  int clear_line(std::vector<int> row);

 private:
  int width;   // nun cols
  int height;  // num rows
  std::vector<std::vector<char>> empty_board;
  std::vector<std::vector<char>> fixed_board;  // holds fixed position items
  std::vector<std::vector<char>> board;

  void initialize_board(int height, int width);
  void set_board(std::vector<std::vector<char>> b);
  void set_fixed_board(std::vector<std::vector<char>> b);
  void reset_board();
};
