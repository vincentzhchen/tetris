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

  // setters and getters
  void save_state();
  std::vector<int> get_line(Shape *shape, const int &row, const int &col,
                            const int &rotation);
  int get_board_height();
  int get_board_width();

  // drawing
  void draw();
  void draw_shape(Shape *shape, const int &row, const int &col,
                  const int &rotation);
  void draw_line(std::vector<int> const &row);
  int clear_line(const std::vector<int> &row);

  // logic
  bool is_collide(Shape *shape, const int &row, const int &col,
                  const int &rotation);
  bool is_valid_board();

 private:
  int width;   // nun cols
  int height;  // num rows
  std::vector<std::vector<char>> empty_board;
  std::vector<std::vector<char>> fixed_board;  // holds fixed position items
  std::vector<std::vector<int>> color_board;   // holds ansi color code
  std::vector<std::vector<char>> board;

  void initialize_board(int height, int width);
  void set_board(std::vector<std::vector<char>> b);
  void set_fixed_board(std::vector<std::vector<char>> b);
  void reset_board();
};
